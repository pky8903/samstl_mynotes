//
//  1_map1_1.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::string> m;
    
    m.emplace("mon", "월요일");
    m.emplace("sun", "일요일");
    
    // map과 range-for
    for (const auto& e : m)
    {
        std::cout << e.first << std::endl;
    }
    
    // C++17부터 가능한 문법
    std::pair<int, int> p(1, 2);
    auto [a, b] = p;    // auto a = p.first
                        // auto b = p.second
                        // 구조체가 가지고 있는 것을 한번에 꺼내는 기술
    
    for (auto [key, value]: m)
    {
        std::cout << key << std::endl;
        std::cout << value << std::endl;
    }
    
    return 0;
}
