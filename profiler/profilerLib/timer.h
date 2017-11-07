#ifndef TIMER_H
#define TIMER_H

#ifdef _WIN32
#include <Windows.h>

class CTimer
{
private:
	long long m_frequency;

public:
	void Init();
	long long GetFreqency() const;
	long long GetTicks() const;

};
#endif

#endif //TIMER_H
