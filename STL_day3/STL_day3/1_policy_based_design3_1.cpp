#include <set> // Red Black Tree
#include <functional>
#include "show.hpp"

template<typename T>
struct Greater
{
    // 함수 객체 만들 때, "Operator()"를 꼭 상수 멤버 함수로 하세요.
    // Const Greater g; 로 만들었어도
    // if ( g(10, 20) ) 할 수 있어야 합니다. g.operator()(10, 20) 호출 가능하게
    inline bool operator()(const T& a, const T& b) const // const T도 받을 수 있도록, 그리고 call by ref로: const T&
    {
        return a > b;
    }
};

int main()
{
//    std::set<int, Greater<int>> s; // Red Black Tree
    std::set<int, std::greater<int> > s;
    
    s.insert(15);
    s.insert(25);
    s.insert(5);
    s.insert(17);
    s.insert(10);

    show(s);
}
