#include "socket.h"

namespace Profiler
{
#ifdef _WIN32
	void CSocket::Init()
	{
		memset( &m_wsaData, 0, sizeof( m_wsaData ) );
		m_socket = INVALID_SOCKET;

		WSAStartup(MAKEWORD(2,2), &m_wsaData);
	}
	void CSocket::Create()
	{
		m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
		DWORD const timeout = 1;
		setsockopt( m_socket, SOL_SOCKET, SO_RCVTIMEO, ( char const* )&timeout, sizeof( timeout ) );
	}
	void CSocket::Shutdown()
	{
		if ( m_socket != INVALID_SOCKET )
		{
			CloseSocket();
		}
		WSACleanup();
	}
	void CSocket::CloseSocket()
	{
		closesocket( m_socket );
		m_socket = INVALID_SOCKET;
	}
	int CSocket::Read( char* const buffer, int const bufferLen ) const
	{
		return recv( m_socket, buffer, bufferLen, 0 );
	}
	void CSocket::Send( char const * const buffer, int const bufferLen ) const
	{
		send( m_socket, buffer, bufferLen, 0 );
	}
	bool CSocket::Connect( char const * address, unsigned short const port ) const
	{
		sockaddr_in serverAddress;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons( port );
		inet_pton( AF_INET, address, &serverAddress.sin_addr );
		return connect( m_socket, ( SOCKADDR* )&serverAddress, sizeof( serverAddress ) ) == 0;
	}
#endif
}