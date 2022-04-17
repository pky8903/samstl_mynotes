//
//  4_smart_pointer3_1.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

template <typename T>
class Ptr
{
    T* obj;
    int* ref;
    
public:
    Ptr(T* p = 0) : obj(p) {
        ref = new int;
        *ref = 1;
    }
    
    // 참조 계수 기반의 스마트 포인터의 복사 생성자
    Ptr(const Ptr& p) : obj(p.obj), ref(p.ref)
    {
        ++(*ref);
    }
    
    ~Ptr() {
        if (--(*ref) == 0){
            delete obj;
            delete ref;
        }
    }

    T* operator->() { return obj; }
    T& operator*() { return *obj; }
};

int main()
{
    // 아래 코드는 참조계수가 3이 됩니다.
    Ptr<int> p1 = new int;
    Ptr<int> p2 = p1;
    Ptr<int> p3 = p1;
}
