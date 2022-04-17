//
//  5_traits2.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>

// Traits: 타입(T)에 대한 다양한 특성을 조사하는 기술
// "템플릿 부분 특수화 문법"으로 만드는 도구

// 만드는 방법
// 1. primary template을 만들고 false를 반환 (value = false라는 의미)
// 2. 조건을 만족하는 (포인터) 경우의 부분 특수화를 만들고 true 반환

template<typename T> struct is_pointer
{
//    bool value = false;     // 1. C++ 이전에는 이렇게 초기화 안되었고
                            // 2. 이 경우는 컴파일 시간 상수가 아닌 변수입니다.
//    enum { value = false }; // C++ 이전 스타일
    static constexpr bool value = false;    //요즘 스타일
};

template<typename T> struct is_pointer<T*>
{
//    enum { value = true };
    static constexpr bool value = true;
};

template<typename T> void printv(const T& b)
{
    if ( is_pointer<T>::value )
        std::cout << "포인터" << std::endl;
    else
        std::cout << "포인터 아님" << std::endl;
    
}

int main()
{
    int n = 10;

    printv(n);
    printv(&n);
}

