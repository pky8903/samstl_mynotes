//
//  8_bind2.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

int main()
{
    void(*f)(int) = &f1; // ok
    f(10); // ok. f1(10)과 동일.
    
    // C언어의 함수 포인터는 불편합니다 (한계가 있음)
    // 1. Signature가 다른 함수 주소를 담을 수 없음.
    // f = &f2; // error
    
    // 2. 멤버 함수의 주소도 담을 수 없다.
    // f = &Machine::mf1; // error
    
}













//
