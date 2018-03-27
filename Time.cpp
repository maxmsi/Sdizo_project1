#include "Time.h"

Time::Time(){
	high_resolution_clock::time_point value_start;
	high_resolution_clock::time_point value_stop;
};
Time::~Time() {};

void Time::start_time() {
	value_start = high_resolution_clock::now();
}

void Time::stop_time() {
	value_stop = high_resolution_clock::now();
}

long Time::work_time() {

	return duration_cast<nanoseconds>(Time::value_stop - Time::value_start).count();

}
