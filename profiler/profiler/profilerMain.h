#ifndef PROFILER_MAIN_H
#define PROFILER_MAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_profilerMain.h"
#include "../../profilerLib/packets.h"

class CProfilerMain : public QMainWindow
{
	Q_OBJECT

private:
	enum EStatusFlags
	{
		SF_CONNECTED = 1 << 0,
		SF_PROFILING = 1 << 1,
	};

private:
	Ui::CProfilerMainClass ui;

	class QTcpServer* m_server;
	class QTcpSocket* m_socket;
	class QLabel* m_msgLabel;

	tTick m_frequency;

	unsigned char m_status;

private slots:
	void NewConnection();
	void Disconnected();
	void StartProfiling(bool checked);
	void StopProfiling(bool checked);
	void ProcessData();

private:
	inline void SetStatus( EStatusFlags const flag, bool const value )
	{
		if ( value )
		{
			m_status |= flag;
		}
		else
		{
			m_status &= ~flag;
		}
	}
	inline bool GetStatus( EStatusFlags const flag ) const
	{
		return m_status & flag;
	}

protected:
	virtual void closeEvent( QCloseEvent *event ) override;

public:
	CProfilerMain(QWidget *parent = Q_NULLPTR);
};

#endif //PROFILER_MAIN_H