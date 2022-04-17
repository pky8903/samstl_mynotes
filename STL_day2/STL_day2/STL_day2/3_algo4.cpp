//
//  3_algo4.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.hpp"

int main()
{
    std::list<int> v = { 1,2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // s의 모든 내용을 뒤집기 1. 멤버 함수 사용 (*prev, *next 주소 swap)
    //v.reverse();
    
    // 2. 알고리즘 사용 // 값을 swap
    std::reverse(v.begin(), v.end());
    
    // 만약에 큰 구조체가 data로 들어있다면 2의 경우에 성능 저하가 있을 수 있다.
    
    show(v);

    return 0;
}



















//
