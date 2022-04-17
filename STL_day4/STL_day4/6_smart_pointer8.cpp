//
//  6_smart_pointer8.cpp
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

//    std::shared_ptr<People> bf; // best friend
    People* bf; // raw pointer이므로 참조 계수 증가 안함
                // 자원 누수 문제는 해결되었으나, 하나의 문제가 남아 있음 (8-1 소스 참고)
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    std::shared_ptr<People> sp2(new People("lee"));

    sp1->bf = sp2.get();
    sp2->bf = sp1.get();
}
