//
//  6_smart_pointer7.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <memory>
#include <string>
#include <iostream>

struct People
{
    std::string name;

    People(std::string n) : name(n) {}
    ~People() { std::cout << name << "파괴" << std::endl; }

    std::shared_ptr<People> bf; // best friend
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    std::shared_ptr<People> sp2(new People("lee"));

    sp1->bf = sp2;
    sp2->bf = sp1;
    // 삭제가 안됨.
    // kim을 가리키는 smart pointer
    // kim을 가리키는 lee의 smart pointer: 참조 계수 2
    // lee를 가리키는 smart pointer
    // lee를 가리키는 kim의 smart pointer: 참조 계수 2
    // kim을 소멸시키면 kim 참조 계수 1
    // lee를 소멸시키면 lee 참조 계수 1
    // 결과적으로 소멸이 안된다! 메모리 누수!
    
}


