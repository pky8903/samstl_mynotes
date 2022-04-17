//
//  3_sequence_container4.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "show.hpp"

// 예전에 만들어 놓은 함수
void foo(int* arr, int sz) {}

int main()
{
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    
    // 예전에 만든 코드로서, foo에 배열을 전달하는 모양
    foo(x, 10);

    // STL을 배우고, 배열 대신 vector를 사용하기로 결정하고
    // vector를 예전에 만든 foo에 전달하는 기술
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

    // foo에 v를 보내기?
    // foo(&v, v.size());  // 문법적으로도 error이고, 의미상도 말이 안됨
    
    // v가 사용하는 내부 버퍼의 주소를 보내야 함.
    // foo(&v[0], v.size());       // 예전에 사용하던 기법
    foo(v.data(), v.size());    // 요즘 기법
}


