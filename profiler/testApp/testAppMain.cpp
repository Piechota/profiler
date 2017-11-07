#ifdef _DEBUG
#pragma comment(lib, "../profilerLib/bin/profilerLib_x64_Debug.lib")
#else
#pragma comment(lib, "../profilerLib/bin/profilerLib_x64_Release.lib")
#endif

#include "../profilerLib/profiler.h"

int main()
{
	int status = 0;

	Profiler::Init();

	while ( status != -1 )
	{
		Profiler::Tick();
		if ( Profiler::IsConnected() )
		{
			status = 1;
		}
		else if ( status == 1 )
		{
			status = -1;
		}
	}
	Profiler::Close();

	return 0;
}