//
//  7_range5.cpp
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
    
    // 핵심. view 중첩
    // std::ranges::take_view tv(v, 5);
    // std::ranges::reverse_view rv(tv);
    
    auto tv = v | std::views::take(5) | std::views::reverse()
    | std::views::filter([](int n) { return n%2 == 0; });
    
    for (auto e : rv)
    {
        std::cout << e << std::endl;
    }
    
}
