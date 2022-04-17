//
//  1_STL_PREVIEW2.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

// 1_STL_PREVIEW1
#include <iostream>
#include <list> // 1. add list header for linked list

int main()
{
    std::list<int> s; // 2. make a linked list object

    s.push_back(10);
    s.push_back(20);
    
    std::list<int> s2 = {1, 2, 3, 4};
    
    std::for_each(s.begin(), s.end(), [](int a){ std::cout << a << std::endl; });
    
}

