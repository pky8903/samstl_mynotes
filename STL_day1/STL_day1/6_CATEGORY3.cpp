//
//  6_CATEGORY3.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
    //std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
    std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

    auto p = std::begin(s);

    // p = p + 3; // cannot be used with std::list. because iterators for list does not provide + operator.
    // ++p; ++p; ++p;
    
    // 반복자를 N만큼 전진시키는 함수
    std::advance(p, 3);  // 1. p가 임의 접근이면 + 사용
                         // 2. 임의 접근이 아니면 ++ 사용
    
    std::cout << *p << std::endl;
}
