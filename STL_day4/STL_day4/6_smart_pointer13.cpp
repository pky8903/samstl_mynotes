//
//  6_smart_pointer13.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <memory>
#include <vector>

struct Point
{
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
    std::vector<Point> v1;
    v1.emplace_back(1, 1);
    v1.emplace_back(2, 2); // v1 파괴시 모든 객체 자동 파괴
    // ---------------------------------
    
    std::vector<Point*> v2;
    v2.push_back(new Point(1, 1));
    v2.push_back(new Point(2, 2));
    
    // v2가 파괴되기 전에 사용자가 new한 것은 꼭 delete 해야한다.
    for (auto p : v2)
        delete p;
    
    // ---------------------------------
    
    std::vector<std::shared_ptr<Point>> v3;
//    v3.push_back(new Point(1, 2)); // error
    v3.push_back(std::shared_ptr<Point>(new Point(1, 2)));  // okay but
    v3.push_back(std::make_shared<Point>(1, 2));            // is better
}
// 스마트 포인터 개념: 1990년대 말에 등장
// boost 라이브러리 2000년 경에 shared_ptr 지원
// C++11 만들 때 C++ 표준으로 "shared_ptr" 채택.

void foo()
{
    int *p = new int;
    
    if (실패)
    {
        delete p;
        return;
    }
    
    delete p; // raw pointer는 이럴 때 너무 불편하다. 일일이 delete 해줘야함
}
