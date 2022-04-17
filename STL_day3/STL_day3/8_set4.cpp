#include "show.h"
#include <set>

struct Compare
{
	bool operator()(int a, int b) const
	{
		return (a / 10) < (b / 10);
	}
};

int main()
{
	std::set<int, Compare> s;
	// 다음중 실패는 ?
	s.insert(15);
	s.insert(25);
	s.insert(45);
	s.insert(35);
	s.insert(22); 
	show(s);

	// 아래 2개의 검색 결과는 어떻게 나올까요 ?
	// 아래 코드가 equality
	auto ret1 = std::find(s.begin(), s.end(), 12); // ==
	
	if (ret1 == s.end())
		std::cout << "실패" << std::endl;

	// 아래는 equivalency 
	auto ret2 = s.find(12); 
	std::cout << *ret2 << std::endl;
}