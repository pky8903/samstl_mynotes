//
//  4_smart_pointer4.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
// C++11 표준 스마트 포인터
#include <memory>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
    // 핵심 1. 표준 스마트 포인터의 이름은 "smart_ptr" 입니다.
    std::shared_ptr<int> p1(new int);   // ok
//    std::shared_ptr<int> p2 = new int;  // error.
                                        // 생성자 앞에 explicit을 붙이면 () 초기화만 가능함

    // 핵심 2. 스마트 포인터의 크기
    //        구현에 따라 달라질 수 있지만 대부분 "raw pointer 크기의 2배"
    std::cout << sizeof(p1)   << std::endl; // 16 왜냐하면 참조 계수 포인터 때문에.
    std::cout << sizeof(int*) << std::endl; // 8

    // 핵심 3. ->와 . 연산자
    std::shared_ptr<Car> sp1(new Car);
    std::shared_ptr<Car> sp2 = sp1;
    
    // -> : 대상체(Car)의 멤버 접근
    sp1->Go();  // Car의 멤버 함수
    
    // .: Shared_ptr자체의 멤버 함수
    int n = sp1.use_count();
    
    std::cout << n << std::endl;

}
