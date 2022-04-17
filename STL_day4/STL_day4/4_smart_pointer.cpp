//
//  4_smart_pointer.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

// 아래 코드가 핵심입니다.
class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car()    { std::cout << "~Car" << std::endl; }
};


// 스마트 포인터란?
// 개념: 임의의 객체가 다른 타입의 포인터 역할을 하는 것
// 원리: ->와 * 연산자를 재정의해서 포인터처럼 보이게 만든 것
// 장점: raw pointer가 아닌 "객체"라는 점!
//      생성/복사/대입파괴의 모든 순간에 해당하는 함수가 호출되고

class Ptr
{
    Car* obj;
public:
    Ptr(Car* p = 0) : obj(p) {}
    
    ~Ptr() {
        delete obj;
    }

    Car* operator->() { return obj; }
    Car& operator*() { return *obj; }
};

int main()
{
    // Ptr 타입의 "객체 p"가 "Car 타입의 포인터"처럼 사용
    // 1. 아래 코드 원리 (메모리 그림 그려보기)
    Ptr p = new Car; // Ptr p(new Car);

    // 2. 아래 코드 원리 생각해볼 것
    p->Go();    // p.operator->()Go()의 모양인데
                // (p.operator->())->Go()로 해석됩니다.
    
    (*p).Go();  // 되나? 안된다. 따라서 연산자 재정의를 해줘야한다. p.operator*()
    
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(Car*) << std::endl;
    
    // smart pointer 좋은 점: p는 객체이기 때문에, 반드시 사라질 때 소멸자가 call 된다 --> 소멸자에서 new로 생성된 메모리 해지 가능!!
}
