//
//  4_algoAndFunc_1.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "show.hpp"
using namespace std;

// single argument function

void foo(int n)
{
    std::cout << n << ", ";
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    // STL 알고리즘에는 "인자를 함수(포인터)"를 받는 경우가 많이 있음.
    
    // 1. for_each 알고리즘
    std::for_each(v.begin(), v.end(), foo);

    return 0;
}



















//
