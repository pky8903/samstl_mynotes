//
//  5_functor7.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{ inline bool operator()(int a, int b) { return a > b; }};

int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

    // C++ 표준 sort()는 템플릿입니다.

    // 1. 비교 정책으로 일반 함수 사용시
    // 장점: 비교 정책 함수를 여러번 교체해도 sort() 함수는 하나만 생성된다. 코드 메모리 증가 안함.
    // 단점: sort() 함수가 하나만 생성되기 때문에 결국엔 호출해야한다. 즉, 비교 함수가 인라인 치환될 수 없다. 성능 저하.
    std::sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int, int))
    std::sort(x, x + 10, cmp2); // sort(int*, int*, bool(*)(int, int))

    // 2. 비교 정책으로 functor 사용시
    
    // 장점: 비교 정책이 인라인 치환될 수 있다. - 빠르다.
    // 단점: 비교 정책을 교체한 횟수만큼 sort() 함수가 생성된다.
    // 코드 메모리 증가.
    Less    f1;
    Greater f2;
    std::sort(x, x + 10, f1); // sort(int*, int*, Less) 모양의 함수를 생성.
    std::sort(x, x + 10, f2); // sort(int*, int*, Greater) 모양의 함수를 생성.
}
