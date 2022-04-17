//
//  7_range4.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <vector>
#include <ranges>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // take_view를 사용하는 법
    // 1. take_view 클래스 이름 직접 사용
    std::ranges::take_view t1(v, 3);
    
    // 2. take_view를 생성하는 take() 함수 사용
    auto tv2 = std::views::take(v, 3);
    
}
