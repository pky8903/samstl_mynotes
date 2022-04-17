#include <iostream>
#include "show.h"

#include <set> // Red Black Tree·Î ±¸Çö

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	auto p = s.begin();
	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p;
	}
	
}







