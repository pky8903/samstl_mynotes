//
//  8_INSERT1.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <iterator>

int main()
{
    std::list<int> s = { 1, 2, 3, 4, 5};

    // 1. push_xxx() memeber function
    s.push_back(10);
    
    // 2. insert iterator
    // "p" is an iterator in the below code
    std::back_insert_iterator<std::list<int> > p(s);
    *p = 20; // s.push_back(20);
    
    for (auto e : s)
        std::cout << e << ", ";
}
