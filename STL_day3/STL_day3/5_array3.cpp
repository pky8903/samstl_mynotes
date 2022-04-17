//
//  5_array3.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <algorithm>
#include "show.hpp"
#include <array> // c++부터 도입.

int main()
{
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
//    arr.push_back(1); // error
//    arr.resize(7);    // error
    
    // std::array는 내부적으로 raw array
    // 그래서 크기 조절 삽입 및 삭제는 모두 불가능
    // 단지 raw array + 몇가지 도움 함수
}
