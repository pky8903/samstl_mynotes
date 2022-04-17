//
//  6_smart_pointer9.cpp
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
//    People* bf; // raw pointer를 사용하면 "상호 참조"의 메모리 누수 문제는 해결!
                // 하지만 "dangling pointer"가 발생할 수 있다!!!
                // 아래 main 함수 참고
    std::weak_ptr<People> bf;   // 참조 계수가 증가하지 않는 스마트 포인터
                                // 객체의 파괴 여부도 조사 가능
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    {
        std::shared_ptr<People> sp2(new People("lee"));
        
        sp1->bf = sp2;
        sp2->bf = sp1;  // weak_ptr은 shared_ptr과 호환됨
    } // 여기서 sp2 파괴됨.

    if (sp1->bf.expired()) // dangling pointer가 여전히 있다.
    {
        // bf 포인터가 0이 아니므로 안전하다고 생각하고 사용
        std::cout << "객체가 파괴되었음." << std::endl;
    }
    else
    {
        std::cout << "객체가 파괴되지 않았음." << std::endl;
        // 파괴되지 않은 경우... 객체에 접근하려면
        // 1. weak로는 접근할 수 없습니다.
        //  => weak는 객체 수명에 관여하지 않으므로 (참조 계수 증가 안함)
        //  => 객체의 멤버 함수 호출 중에 객체가 파괴돌 수도 있다.
        //      그래서 weak로 객체 접근 안된다.
        // auto ret = sp1->bf->name; // error. weak_ptr은 -> 연산자 제고 아안함
        
        // weak를 가지고 shared를 만들어서 접근해야함.
        std::shared_ptr<People> sp = sp1->bf.lock();
        
        if (sp) // 다시 유효성 확인 후 사용
        {
            std::cout << sp->name << std::endl;
        }
        
    }
}
