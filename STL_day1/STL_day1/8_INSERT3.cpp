//
//  8_INSERT3.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <iterator>

int main(int argc, char** argv)
{
    int x[5]    = { 1, 2, 3, 4, 5 };
    std::list<int> s = { 0, 0, 0, 0, 0 };

    // 삽입반복자는 3개가 있다
    // 1. back_inserter
    // std::copy(x, x+5, std::back_inserter(s));
    
    // 2. front_inserter
    //std::copy(x, x+5, std::front_inserter(s));
    
    // 3. random inserter
    // std::container(컨테이너, 삽입할 위치를 나타내는 반복자 p): p 앞에 삽입
    std::copy(x, x+5, std::inserter(s, (s.begin())));
    
    for (auto& n : s)
        std::cout << n << ", ";
}

