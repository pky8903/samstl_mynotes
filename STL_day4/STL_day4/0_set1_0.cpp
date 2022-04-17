//
//  0_set1_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <functional>
#include "show.h"

// set: 집합(교집합, 합집합 등) 관련 연산 제공
#include <set> // Red Black Tree로 구현

int main()
{
//    std::set<int>  s;
    std::set<int, std::greater<int> > s;

    s.insert(20);
    s.insert(30);
    s.insert(15);
    s.insert(5);
    s.insert(40);

    auto p = s.begin();
    while (p != s.end())
    {
        std::cout << *p << std::endl;
        ++p;    // 트리 내에서 왼쪽 정렬 우선 순회
    }
    
    show(s);
    
}

