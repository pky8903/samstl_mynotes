//
//  5_functor5.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <algorithm>
#include "show.hpp"

void Sort(int* x, int sz, bool(*cmp)(int, int))
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            //if (x[i] > x[j])            // 직접 비교가 훨씬 빠르다
            if (cmp(x[i], x[j]) == false) // 느리다
                                          // "STL에서는 비교 정책을 교체하는데 속도를 빠르게 하고 싶었다!"
                std::swap(x[i], x[j]);
        }
    }
}

// Sort에 전달할 비교 정책 함수
inline bool cmp1(int a, int b) { return a < b; } // inline도 결국엔 함수포인터로 부르면 치환이 아니라 호출된다.
bool cmp2(int a, int b) { return a > b; }

int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
    Sort(x, 10, cmp2);
    
    show(x);
}


