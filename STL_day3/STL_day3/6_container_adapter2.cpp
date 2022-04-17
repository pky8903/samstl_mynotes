//
//  6_container_adapter2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

// 3개의 컨테이너 어답터가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue
#include "show.hpp"

template<typename T>
struct debug_alloc
{
    T* allocate(std::size_t sz)
    {
        T* ptr = static_cast<T*>(malloc(sizeof(T)*sz));
        printf("%d allocated at %p\n", (int)sz, ptr);
        return ptr;
    }
    
    void deallocate(T* ptr, std::size_t sz)
    {
        free(ptr);
        printf("%d deallocated at %p\n", sz, ptr);
    }
    
    // 위 2개 위에도 아래 3개가 있어야합니다.
    using value_type = T;
    debug_alloc() {}
    template<typename U> debug_alloc(const U&) {} // template 생성자
};


int main()
{
    std::stack<int> s1;
    s1.push(10);
    
    // 내부 컨테이너를 변경하는 방법
    std::stack<int, std::vector<int> > s2;
    
    // 질문: stack s3를 만드세요
    // 1. 내부 컨테이너를 vector로
    // 2. 단위전략 3-1에 있는 "debug_alloc"을 사용해보기
    
//    std::stack<int, std::vector<int>, debug_alloc<int> > s3; // error
//    1. stack은 템플릿 인자가 2개이고
//    2. stack 자체가 메모리 할당하는 것은 아닙니다.
    
    std::stack<int, std::vector<int, debug_alloc<int> > > s3;
    
    s3.push(10);
    s3.push(20);


}
