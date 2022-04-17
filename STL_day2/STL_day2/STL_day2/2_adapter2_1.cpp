#include <iostream>
#include <list>
#include <algorithm>
#include "show.hpp"

int main()
{
    std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

    auto ret1 = std::find(s.begin(), s.end(), 3);
    auto ret2 = std::find(s.rbegin(), s.rend(), 3);
    
    std::list<int> s2;
    
    
    // s의 모든 내용을 s2로 복사하는데 거꾸로 하고 싶다?
    // 1. 거꾸로해야하므로 - 역반복자
    // 2. s2가 비어있으므로 - 삽입반복자
    // 3. 복사는 copy
    std::copy(s.rbegin(), s.rend(), std::back_inserter(s2));
    
    show(s2);
}
