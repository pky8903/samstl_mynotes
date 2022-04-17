//
//  5_ITERATOR_1.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

// iterator1.cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int x[5] = { 1,2,3,4,5 };

    int* p = x;
    *p; ++p;


    list<int> s = { 1,2,3,4,5 };
    list<int>::iterator p2 = s.begin();
    *p2; ++p2;
}










