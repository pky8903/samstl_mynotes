//
//  6_container_adapter.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 그런데 스택이 필요합니다.
// 1. 새로 만들자.
// 2. list를 스택처럼 보이게 하자.

// "adapter design pattern": 기본 클래스의 인터페이스 (함수 이름)을 변경해서 새로운 클래스를 만드는 디자인 패턴
template<typename T> class stack
{
    std::list<T> c;
    
public:
    // push_back()이라는 함수 이름을 push()라는 이름으로 변경해서 스택처럼
    inline void push(const T& a) { c.push_back(a); }
    inline void pop()  { c.pop_back(); }       // 제거만, 반환 안함
    inline T& top()    { return c.back(); }    // 반환만, 제거 안함
    
};

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);

    std::cout << s.top() << std::endl;

}
