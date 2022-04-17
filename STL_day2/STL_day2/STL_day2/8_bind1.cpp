//
//  8_bind1.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std::placeholders; // _1, _2 ,_3.. 이 namespace안에 있음.

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수..
    
    // std::bind : M항 함수(객체)를 N항 함수로 변경하는 도구, 단 M > N.
    
    // bind 사용법: std::bind(M항 함수, M개 인자)
    std::bind(foo, 1, 2, 3, 4)(); // std::bind(foo, 1, 2, 3, 4)() 가 다시 함수임. 그래서 () 를 마지막에 붙여 함수를 호출함.
                                    // 4항 함수 => 0항 함수
    
    std::bind(foo, 5, 6, _1, 3)(2); //
    
    std::bind(foo, 9, _2, 6, _1)(7, 4); // 9 4 6 7이 나오도록
}

