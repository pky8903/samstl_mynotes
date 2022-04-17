//
//  2_unordered_set1_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <unordered_set>
#include <string>
#include "show.h"

// unordered_set
// hash는 정렬이 안되어있다. 그래서 unordered_set이라고 부른다

int main()
{
    // c++ 표준이 제공하는 "hash 함수"들
    // functor로 되어있습니다.
    std::hash<int> hi;
    std::hash<double> hd;
    std::hash<std::string> hs;

    std::cout << hi(30) << std::endl;
    std::cout << hi(40) << std::endl;
    std::cout << hd(3.4) << std::endl;
    
    std::cout << hs("hello") << std::endl; // hash 값들
}
 
