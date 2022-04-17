#include <set> // Red Black Tree
#include <functional>
#include "show.h"

// STL은 크기 비교도 모두 "단위 전략"으로 합니다.
// 메모리 할당기 조건: allocate, deallocate 필요
// 크기 비교 (Pred) 조건: operator()(T a, T b)가 있어야 한다. a, b의 크기 비교 후 bool 변환
template<typename T, typename Pred = std::less<T>, typename Alloc = std::allocator<T>>
class set
{
    Alloc ax;   // 메모리 할당이 필요할 때 사용
    Pred pred;  // 요소 크기 비교를 위한 객체
public:
    void insert(const T& newElem)
    {
//        if (rootElem < newElem)
        if (pred(newElem, rootElem))
            add right child;
        else if (pred(rootElem, newElem))
            add left child;
        else
            fail;   // set은 요소의 중복을 허용하지 않는다. 이미 요소가 있다는 것.
    }
}

int main()
{
    std::set<int> s; // Red Black Tree ¿‘¥œ¥Ÿ.

    s.insert(15);
    s.insert(25);
    s.insert(5);
    s.insert(17);
    s.insert(10);

    show(s);
}
