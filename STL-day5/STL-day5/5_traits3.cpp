//
//  5_traits3.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <type_traits>

// traits 라이브러리의 2가지 종류
// 1. 타입 질의 : is_xxx        ex) std::is_pointer<T>::value
// 2. 변형타입얻기               ex) std::remove_pointer<T>::type

template<typename T> void foo(const T& b)
{
    // 현재 T는 int, int*입니다. (main 참고)
    typename std::remove_pointer<T>::type n;

    std::cout << typeid(n).name() << std::endl;
}

int main()
{
    int n = 10;

    foo(n);
    foo(&n);
}

