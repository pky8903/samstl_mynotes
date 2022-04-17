#include <vector>
#include <algorithm>
#include "show.hpp"

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };           // 모든 요소가 stack
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };  // 모든 요소가 heap (마음대로 메모리 할당 해지, but 할당 해지에 overload)

	x[0] = 10;
	v[0] = 10;
}
