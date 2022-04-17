//
//  8_INSERT_1_3.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <iterator>

int main()
{
    std::list<int>      s = {1, 2, 3};

    auto p1 = std::back_inserter(s);
    
    *p1 = 10; // s.push_back(10);
    *p1 = 20; // s.push_back(20) 으로 자동 추가
    
    // 원래 모든 반복자는 ++을 해야 다음으로 이동된다.
    // 하지만 삽입 반복자는 ++ 안해도 된다.
    
    *p1 = 30;
    ++p1; // 아무일도 하지 않는다. copy 등에 보내려면 ++이 아무 일도 하지 않아도 제공되긴 해야한다.
    *p1 = 40;
    

}
