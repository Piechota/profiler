#include "timer.h"

void CTimer::Init()
{
	QueryPerformanceFrequency( (LARGE_INTEGER*)&m_frequency );
}

long long CTimer::GetFreqency() const
{
	return m_frequency;
}

long long CTimer::GetTicks() const
{
	LARGE_INTEGER time;
	QueryPerformanceCounter( &time );
	return time.QuadPart;
}
