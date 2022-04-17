//
//  6_smart_pointer12.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

// 핵심 1. 헤더 파일
#include <memory>

struct Point
{
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
    // 핵심 2. std::make_shared를 꼭 사용하세요
//    std::shared_ptr<Point> sp1 = new Point(1, 2); // error
    std::shared_ptr<Point> sp2(new Point(1, 2)); // okay.
    std::shared_ptr<Point> sp3 = std::make_shared<Point>(1, 2); // 권장
    
    // 참고: 삭제자 변경 등도 가능ㅇ하지만 변경할 경우는 많지 않습니다.
    
    // 핵심 3. 상호 참조 가능성이 있는지를 꼭 확인하세요.
    //      => People 처럼 "멤버 데이터로 다시 shared_ptr"이 있는 경우
}
