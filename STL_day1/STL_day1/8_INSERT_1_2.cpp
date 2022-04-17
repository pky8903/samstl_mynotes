//
//  8_INSERT_1_2.cpp
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
    std::vector<int>    v = {1, 2, 3};

    // 삽입 반복자란? 컨테이너에 요소를 추가할 때 사용하는 반복자
    
    // 1. 삽입반복자 클래스 이름 직접 사용.
    std::back_insert_iterator< std::list<int> > p1(s);
    std::back_insert_iterator< std::vector<int> > p2(v);
    
    // 2. 삽입반복자 객체를 만드는 "도움 함수" 사용 (e.g. make_pair
    auto p3 = std::back_inserter(s);
    auto p4 = std::back_inserter(v);
    
    *p3 = 100; // s.push_back(100);
    
    // 3. C++17 부터는
    std::back_insert_iterator p5(s);
    std::back_insert_iterator p6(v);
    
    *p6  = 30; // v.push_back(30);
    

}
