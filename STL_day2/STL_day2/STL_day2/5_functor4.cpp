//
//  5_functor4.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
    // Add1은 inline이 아니므로 "호출"
    // 1. 인자 1, 2를 약속된 장소에 넣어놓고 (32 bit는 sstack, 64bit는 register
    // 2. Add1 함수로 이동
    // push 2
    // push 1
    // call Add1
    int n1 = Add1(1, 2);
    
    // Add2는 inline function이므로 "Add2"를 컴파일 한 후, "Add2의 기계어 코드"
    // 를 아래 코드 왼쪽에 치환
    int n2 = Add2(1, 2);    // mov eax, 2
                            // add eax, 1
                            // mov n2, eax

    int(*f)(int, int) = &Add2;
    
    // if (사용자입력 == 1) f = &Add1;
    // f는 실행시 변경 가능한 변수이므로
    // 컴파일 할 때는 f가 어느 함수를 가리키는지 알 수 없습니다.
    // 그래서 아래 코드는 항상 호출입니다.
    
    f(1, 2); // ?
}
// 핵심 1. inline 치환은 "컴파일"할 때 수행되는 문법이다.
// 핵심 2. inline function이라도 함수 포인터에 의해서 호출되는 것은 변수에 의한 호출이므로, 결국엔 호출이다. 치환이 될 수 없다.

