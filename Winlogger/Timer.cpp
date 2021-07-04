#include"Timer.h"

void Timer::SleepAndRun()
{
	std::this_thread::sleep_for(interval);
	if (alive)
		Function()();
}

void Timer::ThreadFunc()
{
	if (CallNumber == Infinite)
	{
		while (alive)
			SleepAndRun();
	}
	else
	{
		while (repeat_count--)
			SleepAndRun();
	}
}



void Timer::Stop()
{
	alive = false;
	Thread.join();
}

bool Timer::IsAlive() const { return alive; }
