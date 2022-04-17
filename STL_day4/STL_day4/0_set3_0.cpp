//
//  0_set3_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include "show.h"
#include "debug_alloc.h"
#include <set>

// set에 사용자 정의 타입 넣기
// ==> 크기 비교가 가능해야한다.
// 방법 1. 타입 안에 "<" 연산이 가능하도록 연산자 재정의 함수 제공
//          => 꼭, 상수 멤버 함수로 만드세요
//          => 일반적으로 <를 만들면, <=. >, >=, ==, != 등도 제공하는 것
//          => C++20부터는 "<=>"는 이 연산자를 한개만 만들면 6개 비교연산자 자동생성
// 방법 2. 새로운 비교 정책을 가진 함수 객체 제공: Point 객체 2개를 크기 비교할 수 있는 함수 객체를 만들어서 set의 2번째 템플릿 인자로 전달.

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    bool operator<(const Point& pt) const // 뒤에 const를 붙여야한다. 왜냐하면 내부적으로 const object로 call할 수도 있기 때문이다.
    {
        return x < pt.x;
    }
};

struct PointCompare
{
    // class(struct) 만들 때, 선언 안에 함수 구현 자체를 넣으면 암시적으로 인라인처리됨.
    // 그래서 inline 표기하지 않아도 되는데 가독성을 위해 inline표기하는 경우가 많다.
    inline bool operator()(const Point& p1, const Point& p2) const
    {
        return p1.x < p2.x;
    }
};
// C++ 표준 "set"은 "어떻게 동작해야 한다"라고만 정의해야한다.
// set을 만들기 위해 "반드시 tree"를 사용해야하는 것은 아니다.

int main()
{

//    std::set<Point> s;  // 이 경우는 비교시 "less" 사용
                        // less는 결국 "<" 사용하므로 Point 자체가 < 가능해야함.
    
    std::set<Point, PointCompare, debug_alloc<Point> > s;    // Point자체가 < 연산이 되지 않아도 상관없음.
                                        // Point 2개 비교시 PointCompare 객체 사용
    
    // 요소를 넣을 때는
    // 1. insert
    // 2. emplace ==> 사용자 정의 타입일 때는 이것이 좋음.

    s.insert(Point(5, 5));      // 임시 객체로 넣기
    s.insert({5, 5});           // 임시 객체로 넣기
    s.emplace(3, 2);            // 이 코드가 가장 좋음
    s.emplace(2, 1);
    s.emplace(1, 5);
    
    // set의 반복자는
    // tree의 세가지 순회기술
    // post order traversal
    // pre order traversal
    // in order traversal ==> 이 기술로 구현

}


