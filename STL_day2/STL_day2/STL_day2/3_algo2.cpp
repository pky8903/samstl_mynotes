//
//  3_algo2.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.hpp"

// "알고리즘은 컨테이너를 알지 못한다."

int main()
{
    std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

    // remove 알고리즘은 요소를 제거하는 것이 아니라
    // 3을 만나면 뒤의 요소를 앞으로 당겨놓는 역할.
    // 반환값으로 나오는 반복자는 유효한 구간의 마지막 다음 요소를 가리킨다.
    auto p = std::remove(v.begin(), v.end(), 3); // 3이 나오면 3을 지우고 앞으로 당기고 알고리즘을 끝낸다.
    
    std::cout << *p << std::endl;

    show(v);
    
    // 유효하지 않은 구간을 제거하려면 vector의 멤버 함수를 사용해야한다.
    // 컨테이너의 진짜 메모리를 제거하는 것은
    // 알고리즘이 아닌 각 컨테이너의 멤버 함수만이 가능.
    
    v.erase(p, v.end());
    show(v);
    
    // 한 줄로, erase-remove
    v.erase(std::remove(v.begin(), v.end(), 3), v.end());
    show (v);

    return 0;
}



















//
