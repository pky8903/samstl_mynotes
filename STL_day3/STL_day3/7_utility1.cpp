//
//  7_utility1.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream>
#include "show.hpp"

template<typename T, typename U> struct pair
{
    T first;
    U second;
    
    // 생성자들
};
// ---------------------------------------------------

template<typename T> void foo(T a) {}

int main()
{
    // pair : 서로 다른 타입 2개를 보관하는 구조체
    
    std::pair<int, double> p1(1, 3.4);
    
    // 1. 요소 접근
    std::cout << p1.first   << std::endl;
    std::cout << p1.second  << std::endl;
    
    // 2. make_pair (타입 안써도 됨. 유추해서 넣음)
    auto p2 = std::make_pair(1, 3.4);
    
    foo(std::make_pair(1, 3.4)); // 함수 인자를 pair로 보낼 때
                                 // make_pair를 사용하면 편리합니다.
    
    // 3. C++17부터는 pair 자체도 타입생략 가능
    std::pair p3(1, 3.4);

}
