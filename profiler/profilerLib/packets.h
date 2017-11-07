#ifndef PACKETS_H
#define PACKETS_H

typedef long long tTick;

enum class EPacketType : unsigned char
{
	PT_START_PROFILING,
	PT_STOP_PROFILING,
	PT_FREQUENCY,
	PT_FRAME,
	PT_CALL_START,
	PT_CALL_END,
	PT_INVALID,
};

#endif //PACKETS_H
