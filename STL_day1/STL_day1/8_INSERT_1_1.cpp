//
//  8_INSERT_1_1.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <utility>


template<typename T>
T square(T a)
{
    return a * a;
}

// object generator라는 이름을 가진 기술.
template<typename T, typename U>
std::pair<T, U> make_pair(const T& a, const U& b)
{
    return std::pair<T, U>(a, b);
}

int main()
{
    // 다음 중 쉬워보이는 것은?
    //square<int>(3); // 1
    //square(3);       // 2. 쉬워보인다.
    
    std::pair<int, double> p1(3, 3.4); // int, double을 생략할 수 있을까?
    
    // auto p2 = make_pair<int, double>(3, 3.4); // 이 표현이 더 정확하지만,
    auto p2 = make_pair(3, 3.4); // 함수 템플릿: type이 없어도 type 추론함.
    
    // C++17부터는 클래스(구조체) 템플릿도 타입 인자 생략 가능.
}
