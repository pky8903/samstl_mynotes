//
//  4_smart_pointer3.cpp
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
    Ptr<int> p2 = p1;   // 이 때의 문제점? 복사 생성자 호출됨 (사용자가 만들지 않으면 컴파일러 제공 버전 사용)
                        // 얕은 복사의 문제점. p1 p2는 같은 메모리를 가리키는 멤버 변수(포인터)를 가지고 있다.
                        // 그런데 p2가 먼저 사라져버리면 data 소멸시켜버리고 p1은 data가 없는 자리를 가리키게 되어 문제가 발생한다.
                        // 그래서 count를 만들어서 해결한다. p2가 먼저 사라지면 count를 2에서 1로 내리고, p1이 사라질 때 count를 1에서 0으로 내리면서 data 소멸시킴
}
