//
//  5_traits4.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
// traits를 사용하려면 아래 헤더 필요합니다.
#include <type_traits>

template<typename T> void foo(const T& b)
{
    // 조사
    bool b1 = std::is_pointer<T>::value;        // C++11 스타일
    bool b2 = std::is_pointer_v<T>;             // C++17 스타일

    // 변형된 타입 얻기
    typename std::remove_pointer<T>::type n1;   // C++11 스타일
    std::remove_pointer_t<T> n2;                // C++14 스타일
    
}

int main()
{
    int n = 10;

    printv(n);
    printv(&n);
}

