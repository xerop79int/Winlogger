#ifndef __TIMER_H
#define __TIMER_H

#include<thread>
#include<iostream>
#include<chrono>
#include <functional>

class Timer {

	std::thread Thread;
	bool alive = false;
	long CallNumber = -1L;
	long repeat_count = -1L;
	std::chrono::milliseconds interval = std::chrono::milliseconds(0);
	std::function<void(void)> funct = nullptr;
	

	void SleepAndRun();
	void ThreadFunc();

public:
	static const long Infinite = -1L;
	
	Timer() {}
	Timer(const std::function<void(void)>& f) : funct(f) {}
	Timer(const std::function<void(void)> &f,
		const unsigned long &i,
		const long repeat = Timer::Infinite) :  funct(f),
												interval(std::chrono::milliseconds(i)),
												CallNumber(repeat) {}

	void Start(bool Async = true)
	{
		if (IsAlive())
			return;
		alive = true;
		repeat_count = CallNumber;
		if (Async)
			Thread = std::thread(&Timer::ThreadFunc, this);
		else
			this->ThreadFunc();
	}
	void Stop();
	bool IsAlive() const ;

	const std::function<void(void)> &Function() const
	{
		return funct;
	}
};
#endif // !__TIMER_H