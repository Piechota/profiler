#include "profiler.h"
#include "packets.h"
#include "timer.h"

namespace Profiler
{
	CTimer _timer;
	CSocket _socket;
	TSimpleArray< char > _stream;
	unsigned char _status;

	void SetStatus( EStatusFlags const flag, bool const value )
	{
		if ( value )
		{
			_status |= flag;
		}
		else
		{
			_status &= ~flag;
		}
	}
	bool GetStatus( EStatusFlags const flag )
	{
		return _status & flag;
	}
	bool IsConnected()
	{
		return _status & EStatusFlags::SF_CONNECTION;
	}

	void Frame( unsigned int const frameID )
	{}

	template< class T >
	void ReadBuffer( T& object, char const*& buffer, int& bufferSize )
	{
		object = *( ( T* )buffer );
		buffer += sizeof( T );
		bufferSize -= sizeof( T );
	}

	void TryConnect()
	{
		if ( _socket.Connect( "127.0.0.1", 4372 ) )
		{
			_status |= EStatusFlags::SF_CONNECTION;

			char buffer[ sizeof( EPacketType ) + sizeof( tTick ) ];
			*( ( EPacketType* )buffer ) = EPacketType::PT_FREQUENCY;
			*( ( tTick* )&buffer[ sizeof( EPacketType ) ] ) = _timer.GetFreqency();

			_socket.Send( buffer, sizeof( buffer ) );
		}
	}

	void ProcessPackets( int bufferSize )
	{
		char const* buffer = _stream.Begin();
		while ( 0 < bufferSize )
		{
			EPacketType recvPacket = EPacketType::PT_INVALID;
			ReadBuffer( recvPacket, buffer, bufferSize );

			switch ( recvPacket )
			{
				case EPacketType::PT_START_PROFILING:
					SetStatus( EStatusFlags::SF_PROFILING, true );
					break;
				case EPacketType::PT_STOP_PROFILING:
					SetStatus( EStatusFlags::SF_PROFILING, false );
					break;
			}
		}
	}

	bool Init()
	{
		_timer.Init();
		_stream.Resize( 256 );

		_status = 0;
		_socket.Init();
		_socket.Create();

		return _socket.IsValid();
	}

	void Close()
	{
		_socket.Shutdown();
	}

	void Tick()
	{
		if ( IsConnected() )
		{
			int const bytesNum = _socket.Read( _stream.Begin(), _stream.Size() );
			if ( 0 < bytesNum )
			{
				ProcessPackets( bytesNum );
			}
			else if ( bytesNum == 0 )
			{
				_status &= ~EStatusFlags::SF_CONNECTION;
				_socket.CloseSocket();
				_socket.Create();
			}
		}
		else
		{
			TryConnect();
		}
	}
}