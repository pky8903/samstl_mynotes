//
//  7_utility2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <tuple>
#include <iostream>

int main()
{
    // pair : C++98. 서로 다른 타입의 객체 2개 보관
    std::pair<int, double> p1(3, 3.4);
    
    // 3, 4 ... 도 보관 가능합니다.
    std::pair<int, std::pair<int, double> > p2(3, std::pair<int, double>(1, 3.4));
    
    std::cout << p2.first << std::endl; // 3
    std::cout << p2.second.first << std::endl; // 1
    std::cout << p2.second.second << std::endl; // 3.4
    
    // 위처럼 하면 pair에 몇개라도 넣을 수 있지만, 너무 복잡하고 불편하다.
    // 그래서 C++11부터는 tuple 제공
    
    std::tuple<> t0; // 0개 보관
    std::tuple<int, double> t2(1, 3.4);
    std::tuple<int, double, char, short> t4(1, 3.4, 'A', 3);
    
    // tuple의 요소 접근은 std::get 사용
    std::get<0>(t4) = 30;
    std::cout << std::get<0>(t4) << std::endl;

}
