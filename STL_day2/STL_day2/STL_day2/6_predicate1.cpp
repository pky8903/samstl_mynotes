//
//  6_predicate1.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

// 조건자(predicator): bool을 반환하는 함수(혹은 functor)
bool foo(int n) { return n % 3 == 0; }

int main()
{
    std::vector<int> v = {1, 2, 6, 4, 5, 3, 7, 8, 9, 10};
    
    // serach 3
    auto ret1 = std::find(v.begin(), v.end(), 3);
    
    // 주어진 구간에서 첫번째 나오는 3의 배수를 찾고 싶다.
    // std::find: 값 검색, 3번째 인자로 값
    // std::find_if: 조건 검색, 3번째 인자로 함수
    auto ret2 = std::find_if(v.begin(), v.end(), foo);
    auto ret3 = std::find_if(v.begin(), v.end(),
                             [] (int n) { return n % 3 == 0; });
}
