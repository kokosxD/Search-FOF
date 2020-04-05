#include <chrono>
#include "timer.h"

void kokos::Timer::Start() noexcept{
	timer = static_cast<unsigned int>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count());
}

const unsigned int kokos::Timer::Stop() const noexcept{
	return static_cast<unsigned int>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() - timer);
}