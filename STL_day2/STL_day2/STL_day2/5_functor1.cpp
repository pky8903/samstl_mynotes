//
//  5_functor1.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>

// function object("함수객체", functor)
// => () 연산자 함수를 재정의해서 함수처럼 사용가능한 객체.
// => 객체지만 함수처럼 사용가능하다고 해서 "함수객체"라고 합니다.
// 왜 functor를 사용하나?
// 장점 1. 상태를 가지는 함수
// 장점 2. 특정 상황에서 일반함수보다 functor가 더 빠르다.

struct Plus
{
    int operator()(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Plus p; // plus라는 구조체 타입의 객체 p. p는 함수가 아닙니다. 객체입니다.

    int n = p(1, 2); // p는 객체인데 함수처럼 사용된다. "함수 객체".
                
    // 아래 네줄에서 a가 사용자 정의 타입이라면
    // a + b; // a.operator+(b)
    // a - b; // a.operator-(b)
    // a();   // a.operator()()
    // a(1,2); // a.operator()(1, 2)를 컴파일러가 찾음.
}

