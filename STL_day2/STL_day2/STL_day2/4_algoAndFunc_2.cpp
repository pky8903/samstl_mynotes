//
//  4_algoAndFunc_2.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <list>
#include <algorithm>
#include "show.hpp"

int foo(int a, int b)
{
    return a + b;
}

int main()
{
    std::list<int> s1 = { 1,2,3,4,5};
    std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s3;

    // transform algorithm
    std::transform(s1.begin(), s1.end(),
                   s2.begin(),
                   std::back_inserter(s3),
                   [](int a, int b) { return a+b; });

    show(s3);
    
    return 0;
}



















//
