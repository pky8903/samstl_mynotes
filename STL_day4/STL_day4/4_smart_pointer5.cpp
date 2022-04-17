//
//  4_smart_pointer5.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <memory>
void* operator new(size_t sz)
{
    std::cout << "new : " << sz << std::endl;
    return malloc(sz);
}

struct Point
{
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}
};



int main()
{
    // 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
    // 2번 : 객체 생성, 관리 객체 생성
//    std::shared_ptr<Point> sp(new Point(1, 2));


    // make_shared<T> : T 타입객체와 관리객체를 한번에 메모리할당해달라
    //                    sizeof(T) + sizeof(관리객체) 를 한번에 할당
    std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
                            // 1. sizeof(Point) + sizeof(관리객체)를 한번에 할당후
                            // 2. 해당 메모리를 가리키는 shared_ptr을 만들어서 반환
    
    // 핵심 1.
    // shared_ptr 사용시 (1) 보다는 (2)가 좋습니다.
    //(1) std::shared_ptr<Point> sp(new Point(1, 2));
    //(2) std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
    
    // 핵심 2. make_shared의 2가지 장점
    // 1. 효율적인 메모리 관리(객체 + 관리객체)를 한번에 할당
    // 2. 자원관리가 보다 안전하다.

    // (1)->(2)->(3) 의 순서로 실행되면 안전합니다.
    // (1)->(3)->(2) 의 순서로 실행되고, goo에서 예외가 발생하면
    //                                할당된 메모리(new int)는 제거될수 없습니다.
    foo( std::shared_ptr<int>(new int), goo() );
    //            (2)           (1)      (3)

    // 결론, "자원할당" 과 "자원관리객체"의 생성은 반드시 한번에 이루어져야 합니다.
    // 중간에 다른 작업이 있게 되면 위험(다른작업에서 예외발생등)합니다.

    // 아래 코드에서 (1) 은 자원(int)의 할당과 스마트 포인터의 생성을 한번에 하는 함수
    foo(std::make_shared<int>(0), goo());
    //      (1)                      (2)


}


void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }
