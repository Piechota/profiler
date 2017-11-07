#include <QtNetwork\qtcpserver.h>
#include <QtNetwork\qtcpsocket.h>
#include <QtWidgets\qlabel.h>

#include "profilerMain.h"

CProfilerMain::CProfilerMain(QWidget *parent)
	: QMainWindow(parent)
	, m_frequency( 0 )
	, m_status( 0 )
{
	ui.setupUi(this);

	m_msgLabel = new QLabel( this );
	ui.m_statusBar->addWidget( m_msgLabel );

	m_server = new QTcpServer( this );
	if ( !m_server->listen( QHostAddress( "127.0.0.1" ), 4372 ) )
	{
		m_msgLabel->setText( "Can't listen" );
	}
	else
	{
		m_msgLabel->setText( "Waiting for connection" );
	}

	this->connect( m_server, &QTcpServer::newConnection, this, &CProfilerMain::NewConnection );
	this->connect( ui.m_btnStart, &QPushButton::clicked, this, &CProfilerMain::StartProfiling );
	this->connect( ui.m_btnStop, &QPushButton::clicked, this, &CProfilerMain::StopProfiling );
}

void CProfilerMain::closeEvent(QCloseEvent *event)
{
	if ( m_server->isListening() )
	{
		m_server->close();
	}
}

void CProfilerMain::NewConnection()
{
	if ( m_server->hasPendingConnections() )
	{
		m_socket = m_server->nextPendingConnection();
		this->connect( m_socket, SIGNAL(disconnected()), this, SLOT(Disconnected()));
		this->connect( m_socket, SIGNAL(readyRead()), this, SLOT(ProcessData()));

		SetStatus( EStatusFlags::SF_CONNECTED, true );
		SetStatus( EStatusFlags::SF_PROFILING, false );
		m_msgLabel->setText( "Connected" );
		ui.m_btnStart->setEnabled( true );
	}
}

void CProfilerMain::Disconnected()
{
	m_status = 0;

	m_msgLabel->setText( "Waiting for connection" );
	ui.m_statusBar->showMessage( "Disconnected", 2500 );
	ui.m_btnStart->setEnabled( false );
	ui.m_btnStop->setEnabled( false );
}

void CProfilerMain::StartProfiling( bool checked )
{
	EPacketType const startPacket = EPacketType::PT_START_PROFILING;
	m_socket->write( (char*)&startPacket, sizeof( startPacket ) );

	ui.m_btnStart->setEnabled( false );
	ui.m_btnStop->setEnabled( true );
	m_msgLabel->setText( "Profiling..." );
}

void CProfilerMain::StopProfiling( bool checked )
{
	EPacketType const stopPacket = EPacketType::PT_STOP_PROFILING;
	m_socket->write( (char*)&stopPacket, sizeof( stopPacket ) );

	ui.m_btnStart->setEnabled( true );
	ui.m_btnStop->setEnabled( false );
	m_msgLabel->setText( "Connected" );
}

void CProfilerMain::ProcessData()
{
	EPacketType packet = EPacketType::PT_INVALID;
	while ( m_socket->read( ( char* )&packet, sizeof( packet ) ) != 0 )
	{
		switch ( packet )
		{
			case EPacketType::PT_FREQUENCY:
				m_socket->read( ( char* )&m_frequency, sizeof( m_frequency ) );
				break;
		}
	}
}
