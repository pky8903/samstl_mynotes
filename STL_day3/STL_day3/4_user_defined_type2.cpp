//
//  4_user_defined_type2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include "show.hpp"

class Point
{
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b)
    {
        std::cout << "Point()" << std::endl;
    }
    ~Point() { std::cout << "~Point()" << std::endl; }
    
    Point(const Point& p)
    {
        std::cout << "Point(const Point&)" << std::endl;
    }
};
int main()
{
    std::vector<Point> v;

    // 실행결과 예측
    // 1. 객체를 생성 후 넣기
//    Point pt(1, 2);     // 생성자 call
//    v.push_back(pt);    // 복사생성자 call 코드가 끝난 후에 (e.g. ------------------) 소멸자 2개
    
    // 2. 임시객체로 전달
    // 이 경우도 객체가 2개이므로, 소멸자가 2번 호출
    // 단, 임시객체이므로 아래 문장이 끝나면 바로 파괴
//    v.push_back( Point(1, 2) ); // 임시소멸자가 밑줄 위에서 나옴 (c.f. 위는 밑줄 다음에 나옴)
    
    // 3. {1, 2} 도 역시 임시 객체 생성입니다.
//    v.push_back( {1, 2} ); // Point{1, 2} 즉, Point(1, 2)와 동일
    
    // 4. 임시객체의 생성이 아닌,
    // 객체를 만들기 위한 생성자 인자를 전달
    // 생성자 소멸자 1번씩만 호출. 따라서 사용자 정의 타입을 넣을 땐, emplace_back이 훨씬 좋다.
    v.emplace_back(1, 2);   // {1, 2}가 아닌 2개의 인자입니다.
                            // new Point(1, 2)로 만들어달라는 것.

    std::cout << "------------------" << std::endl;
}

// 핵심
// 1. 컨테이너가 "사용자 정의 타입을 값"으로 보관하는 경우
// push_xxx()보다 emplace_xxx()가 좋습니다.

// 2. 단, int 타입이나 사용자 정의 타입의 포인터(Point*)를 보관하는 경우는 그냥 push_xxx()로 넣어도 됩니다. emplace_xxx()도 사용 가능
