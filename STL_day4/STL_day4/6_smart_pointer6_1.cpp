//
//  6_smart_pointer6_1.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <memory>

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
    // 1. sp1 보다, sp2가 좋은 코드 입니다.
    std::shared_ptr<Point> sp1( new Point(1, 2) );

    std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);


    // 2. make_shared 사용시, 객체를 사용자가 만드는 것이 아니라
    //    make_shared 내부에서 만들기 때문에 메모리 할당방식은 바꿀수 없습니다.
    //    그래서, 삭제자 변경도 안됩니다.
    std::shared_ptr<Point> sp3 = std::make_shared<Point>(1, 2);


    // 3. make_shared 와 유사한 방법을 사용하는데,
    //    삭제자를 변경하려면, 객체 생성 방법도 같이 전달해야 합니다.
    std::allocator<Point> ax;
    std::shared_ptr<Point> sp3 =
            std::allocate_shared<Point>( ax, 1, 2);
}

