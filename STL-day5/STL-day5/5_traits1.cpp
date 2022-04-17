//
//  5_traits1.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//
// 4_traits
#include <iostream>
#include <type_traits> // C++ 11 에서 추가된 라이브러리

/*
template<typename T> void printv(const T& v)
{
    if (std::is_pointer<T>::value)
        std::cout << v << " : " << *v << std::endl;
    else
        std::cout << v << std::endl;
}
 */

// C++17의 새로운 if 문: if constexpr
// => 컴파일 시간 if문, 템플릿 만들 때 주로 사용
// => 조건이 false인 경우, 실제 C++ 코드 (함수, 클래스)를 만들 때 포함되지 않는다.

template<typename T> void printv(const T& v)
{
    if constexpr (std::is_pointer<T>::value)
        std::cout << v << " : " << *v << std::endl;
    else
        std::cout << v << std::endl;
}

int main()
{
    int n = 10;
    double d = 10;

    printv(n);
    printv(d);
    printv(&n);
}

