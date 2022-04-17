//
//  5_ITERATOR_2.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <filesystem>

int main()
{
    // 반복자는 컨테이너로부터 꺼내는 것 외에도 많은 종류가 있음.
    std::filesystem::directory_iterator p("C:\\windows");

    std::cout << *p << std::endl;
    ++p;
    std::cout << *p << std::endl;
}










