//
//  5_functor6_1.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <algorithm>
#include "show.hpp"

struct Less
{
    inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
    inline bool operator()(int a, int b) { return a > b; }
};


void Sort(int* x, int sz, Less cmp)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            //if (x[i] > x[j])
            if (cmp(x[i], x[j]) == false) // inline 치환에는 성공했음. 하지만 어떻게 greater로 바꿀까>
                                         
                std::swap(x[i], x[j]);
        }
    }
}

// 비교 정책을 교체할 수 있는데,
// 비교 정책 함수(객체)의 인라인 치환이 가능한 sort()를 만드는 기술
// template + functor를 사용하는 기술로 "STL 설계원리"
// template을 이용하는 것의 단점: sort<Less>, sort<Greator>를 따로따로 기계어로 생성한다. 코드 메모리가 살짝 증가한다.
template<typename T>
void Sort(int* x, int sz, T cmp)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            //if (x[i] > x[j])
            if (cmp(x[i], x[j]) == false) // inline 치환에는 성공했음. 하지만 어떻게 greater로 바꿀까? template
                                         
                std::swap(x[i], x[j]);
        }
    }
}

int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

    Less    f1; f1(1, 2); Sort(x, 10, f1); // f1 f2는 signature는 동일하지만 다른 타입이다. functor는 자신만의 타입이 있다.
    Greater f2; f2(1, 2);
}
