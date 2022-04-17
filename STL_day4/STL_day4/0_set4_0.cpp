//
//  0_set4_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include "show.h"
#include "debug_alloc.h"
#include <set>

// set의 find의 원리: equality를 찾는게 아니라 equivalency를 찾는다.
//if ( root < newelem ) // 정확히는 less 객체 사용
//    move left child;
//else if ( newelem < root )
//    move right child;
//else
//    같다고 확인 (크지도 않고 같지도 않으면! 으로 같음을 판단하기 때문에 == 오퍼레이터가 필요가 없다).
// 즉 s.find의 원리는 ==로 검색이 아니라
// 크지도 않고, 작지도 않으면 "찾았다"라고 판단.


struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    bool operator<(const Point& pt) const // 뒤에 const를 붙여야한다. 왜냐하면 내부적으로 const object로 call할 수도 있기 때문이다.
    {
        return x < pt.x;
    }
};

int main()
{

    std::set<Point> s;  // 이 경우는 비교시 "less" 사용
                        // less는 결국 "<" 사용하므로 Point 자체가 < 가능해야함.
    

    s.emplace(3, 2);            // 이 코드가 가장 좋음
    s.emplace(2, 1);
    s.emplace(1, 5);
    
    s.emplace(2, 5);        // 실패. 우리는 x만 고려하고 있는데 set에 또 같은 원소를 넣으려고 하는 것이므로.
    
    Point pt(3, 2);
    
    auto ret = s.find(pt);  // s.find(Point(3, 2))처럼 해도 됩니다.
                            // 현재 이 코드가 왜 에러가 없을까요?
                            // 검색하려면 ==가 필요하지 않을까요?
    
    if (ret == s.end())
        std::cout << "검색실패" << std::endl;
    else
        std::cout << "검색성공" << std::endl;
    
    // 알고리즘 find는 "==" 연산으로 검색합니다. - equality
    auto ret2 = std::find(s.begin(), s.end(), pt);  //  error
                                                    // Point는 == 연산이 안되기 때문.
    
    // s.find: 크지도 않고 작지도 않으면 "같다" - equivalency
    // std::find : ==로 검색 - equality

}
