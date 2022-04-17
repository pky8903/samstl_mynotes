#include <iostream>
#include <unordered_set>
#include "show.h"
struct People
{
	std::string name;
	int  age;

	People(std::string n, int a) : name(n), age(a) {}
};

int main()
{
	std::unordered_set<People> s;

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);

	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}

