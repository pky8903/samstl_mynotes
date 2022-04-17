//
//  5_ITERATOR_4.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <vector>

// π›∫π¿⁄ π´»ø»≠
int main()
{
    std::vector<int> v = { 1,2,3,4,5 };
    
    auto p = std::begin(v); // v.begin()

    std::cout << *p << std::endl; // 1
    
    v.resize(10); // vector는 연속된 메모리를 사용함!
                // 그런데 resize를 하면 재할당받을 것임 (크기를 키우기 위해).
                // iterator invalidate (반복자 무효화)
    
    std::cout << *p << std::endl; // segmentation fault
}



