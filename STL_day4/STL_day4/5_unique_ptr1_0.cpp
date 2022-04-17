//
//  5_unique_ptr1_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

template<typename T>
class Ptr
{
    T* obj;
public:
    Ptr(T* p = 0) : obj(p) {}
    T* operator->() { return obj; }
    T& operator*() { return *obj; }
    ~Ptr() { delete obj; }
    
    // 복사 생성자 자체를 사용할 수 없게 한다.
    Ptr(const Ptr& p) = delete; // 복사 생성자 삭제 (함수 삭제)
    Ptr& operator=(const Ptr&) = delete;    // 복사생성자를 삭제하면
                                            // 대입연산자도 삭제하는 것이 원칙.
};

int main()
{
    Ptr<int> p1 = new int;
    *p1 = 100;
    std::cout << *p1 << std::endl;

//    Ptr<int> p2 = p1; // 복사 생성자가 삭제되었으므로 "컴파일 에러"
}

