#pragma once
#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono;


class Time
{
public:

	Time();
	~Time();
	high_resolution_clock::time_point value_start;
	high_resolution_clock::time_point value_stop;

	void start_time();

	void stop_time();

	long work_time();

};

