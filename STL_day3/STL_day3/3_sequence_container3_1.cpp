//
//  3_sequence_container3_1.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "show.hpp"

// capacity 개념
int main()
{
    // 사용자가 -1을 입력할때까지 계속 입력받아서 보관하고 싶다.
//    std::vector<int> v(100);    // 이렇게 해놓으면 항상 size = 100이므로, 몇개 입력되었는지 파악이 안됨.
    std::vector<int> v;
    v.reserve(100); // 100개 미리 확보, 생성자 100번 안함
    
    int num = 0;
    while (1)
    {
        std::cin >> num;
        
        if (num == -1) break;
        v.push_back(num);
    }
    std::cout << v.size() << std::endl;
}




