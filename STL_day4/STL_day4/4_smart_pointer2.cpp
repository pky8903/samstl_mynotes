//
//  4_smart_pointer2.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

// 스마트 포인터는 템플릿으로 만들어야합니다.
template <typename T>
class Ptr
{
    T* obj;
public:
    Ptr(T* p = 0) : obj(p) {}
    
    ~Ptr() {
        delete obj;
    }

    T* operator->() { return obj; }
    T& operator*() { return *obj; }
};

int main()
{
    Ptr<int> p1 = new int;
    *p1 = 10;
    std::cout << *p1 << std::endl;
}
