#ifndef PROFILER_H
#define PROFILER_H

#include "socket.h"
#include "simpleArray.h"

namespace Profiler
{
	enum EStatusFlags
	{
		SF_CONNECTION = 1 << 0,
		SF_PROFILING = 1 << 1,
	};

	inline bool GetStatus( EStatusFlags const flag );

	bool Init();
	void Close();

	void Tick();

	bool IsConnected();

	void Frame( unsigned int const frameID );
}

#endif //PROFILER_H