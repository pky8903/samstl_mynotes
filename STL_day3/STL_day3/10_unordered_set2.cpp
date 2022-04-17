#include <iostream>
#include <unordered_set>
#include "show.h"

int main()
{
	std::unordered_set<int> s;

	s.insert(10);
	s.insert(35);
	s.insert(20);
	s.insert(25);

	auto p = s.find(20);  // 해쉬 함수를 사용해서 검색

	std::cout << *p << std::endl;

	show(s);
}

