//
//  6_smart_pointer8_1.cpp
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
    People* bf; // raw pointer를 사용하면 "상호 참조"의 메모리 누수 문제는 해결!
                // 하지만 "dangling pointer"가 발생할 수 있다!!!
                // 아래 main 함수 참고
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    {
        std::shared_ptr<People> sp2(new People("lee"));
        
        sp1->bf = sp2.get();
        sp2->bf = sp1.get();
    } // 여기서 sp2 파괴됨.

    if (sp1->bf != 0) // dangling pointer가 여전히 있다.
    {
        // bf 포인터가 0이 아니므로 안전하다고 생각하고 사용
        std::cout << sp1->bf->name << std::endl;
    }
}
