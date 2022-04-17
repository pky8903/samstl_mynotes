#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;

int main()
{
	// 1. predefined typedef
	hours		 h(1);     // typedef duration<int, ratio<3600,1>> hours;
	minutes      m  = h;
	seconds      s  = h;
	milliseconds ms = h;
	microseconds us = h;
	nanoseconds  ns = h;

	std::cout << h.count() << std::endl;
	std::cout << m.count() << std::endl;
	std::cout << s.count() << std::endl;
	std::cout << ms.count() << std::endl;
	std::cout << us.count() << std::endl;
	std::cout << ns.count() << std::endl;

	// 2. literals( h, min, s, ms, us, ns )
	seconds sec = 1min;

	sec = 1min + 3s;
	sec += 40s;
	std::cout << sec.count() << std::endl;

	seconds sec2 = 1min + 3s;
	std::cout << sec2.count() << std::endl;
}