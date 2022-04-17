//
//  5_ITERATOR_5.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>

int main()
{
    std::list<int> s1 = { 1,2,3 };

    auto p1 = std::begin(s1);   // iterator points the first element
    auto p2 = std::end(s1);     // iterator points the last element
                                // "past the end""

    *p1 = 10; // okay
    *p2 = 20; // runtime error. the end iterator always should be used for comparsion
    
    // [p1, p2)
    while (p1 != p2)
    {
        ++p1;
    }

    std::list<int> s3;
    if (s3.empty()) {}

    if (std::begin(s3) == std::end(s3)) {} // means empty container
}
