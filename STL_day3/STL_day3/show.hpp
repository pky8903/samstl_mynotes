//
//  show.hpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream> // c++ 표준 파일 클래스

// container ver.
template<typename Container>
void show(const Container& c)
{
    for (auto& e: c)
    {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

// iterator ver
template<typename InputIter>
void show(InputIter first, InputIter last)
{
    std::ostream_iterator< typename std::iterator_traits<InputIter>::value_type > p(std::cout, ", "); // 중요함.
    std::copy(first, last, p);
    std::cout << std::endl;
}
