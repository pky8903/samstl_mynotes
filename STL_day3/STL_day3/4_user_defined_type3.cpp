//
//  4_user_defined_type3.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <algorithm>
#include "show.hpp"
class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b)
    {
    }
    
    ~Point() {}
    
    inline bool operator<(const Point& p1) const
    {
        return this->x < p1.x;
    }

    void dump() const
    {
        std::cout << x << ", " << y << std::endl;
    }
};
int main()
{
    std::vector<Point> v;

    v.emplace_back(1, 2); // Point(1,2)
    v.emplace_back(2, 3);
    v.emplace_back(3, 2);
    v.emplace_back(0, 1);

    // 핵심: 사용자 정의 타입을 컨테이너에 넣는 것은 문제가 없다.
    // 2. 그런데 일부 알고리즘 적용시 알고리즘이 요구하는 연산을 잘생각해야한다.
    
//    std::sort(std::begin(v), std::end(v));  // 크기 비교가 안되니 error. 크기 비교 정책 필요.
    
    // 방법 1. sort의 마지막 인자로 Point 2개를 비교하는 조건자 전달
    std::sort(std::begin(v), std::end(v),
              [](const Point& p1, const Point& p2){ return p1.x < p2.x; });
    
    // 방법 2. Point 타입 안에 "Operator<()"를 만들어서 크기 비교가 가능하도록.
    std::sort(std::begin(v), std::end(v));      // now it works

}
