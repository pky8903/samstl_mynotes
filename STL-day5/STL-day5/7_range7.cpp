//
//  7_range7.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4 };
    
    // 아래 3줄을 평가해보기
    auto p1 = v.begin();
    auto p2 = std::vector<int>{1, 2, 3}.begin();    // 반복자 무효화 (임시객체가 파괴되니까)
    auto p3 = std::begin(std::vector<int>{1, 2, 3});    // 반복자 무효화 (임시객체가 파괴되니까)
    
    // 새로운 begin을 만들자
    
    //    *p2 = 10;

        // 위처럼 기존의 begin 은 몇가지 문제가 있었습니다.
        // 그래서 새로운 begin 을 만들었습니다.
        auto p4 = std::ranges::begin(std::vector<int>{1, 2, 3});
    //    auto p4 = std::ranges::begin(v);

}
