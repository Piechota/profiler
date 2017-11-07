#ifndef SOCKET_H
#define SOCKET_H

#ifdef _WIN32
#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>

namespace Profiler
{
	class CSocket
	{
	private:
		WSADATA m_wsaData;
		SOCKET m_socket;

	public:
		void Init();
		void Create();
		void Shutdown();
		void CloseSocket();
		int Read( char* const  buffer, int const bufferLen ) const;
		void Send( char const* const buffer, int const bufferLen ) const;
		bool Connect( char const* address, unsigned short const port ) const;
		bool IsValid() const { return m_socket != INVALID_SOCKET; }
	};
}
#endif

#endif //SOCKET_H
