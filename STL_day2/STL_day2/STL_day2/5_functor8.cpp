//
//  5_functor8.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <vector>
#include <algorithm>
#include <functional> // 이 안에 이미 만들어진 다양한 functor가 있다.
                      // less<>, greator<> 등
#include "show.hpp"

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
//struct Less   { inline bool operator()(int a, int b) { return a < b; }};
//struct Greater{ inline bool operator()(int a, int b) { return a > b; }};

int main()
{
    std::vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    
    // STL에서 sort()를 사용하는 방법
    // A. 비교 정책을 전달 안하는 경우
    std::sort(v.begin(), v.end()); // 오름 차순 정렬
    
    // B. 비교 정책을 전달하는 경우
    // 1. 일반 함수
    std::sort(v.begin(), v.end(), cmp1);
 
    // 2. 함수 객체 전달
    std::less<int> f;
    std::sort(v.begin(), v.end(), f);
    //std::sort(v.begin(), v.end(), std::less<int>()); // 임시 객체 표기법으로 전달
    
    // 3. C++11부터는 람다 표현식
    std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
    
}
