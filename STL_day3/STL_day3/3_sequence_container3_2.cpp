//
//  3_sequence_container3_2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "show.hpp"

// 아래 코드를 보고
// std::remove() vs v.erase() vs v.resize()
int main()
{
    std::vector<int> v = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1};
    
    // 3을 모두 제거하고 싶다.
    auto p = std::remove(v.begin(), v.end(), 3);
    
    std::cout << v.size() << ", " << v.capacity() << " : ";
    show(v);
    
    // 아래 코드는 p~ v.end()를 제거하는 코드
    v.erase(p, v.end()); // list는 진짜 메모리를 줄인다.
    
    std::cout << v.size() << ", " << v.capacity() << " ; "; // erase는 메모리를 줄이진 않는다.
    show(v);
    
    // 실제 메모리를 줄이려면 resize() 혹은 shrink_to_fit
    v.shrink_to_fit(); // v.resize(v.size()) 의 의미.
    std::cout << v.size() << ", " << v.capacity() << " : ";
    show(v);
}
