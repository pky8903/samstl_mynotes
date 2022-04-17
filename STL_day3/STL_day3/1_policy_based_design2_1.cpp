#include <vector>
#include <iostream>

// STL 컨테이너에 전달할 메모리 할당 정책을 담은 할당기 만들기
// 메모리 할당, 해지 정책을 담은 allocate/deallocate 함수를 제공하면 된다.
// interface 기반 가상함수는 성능이 떨어진다. 따라서 C++에서는 그냥 문서로 약속하고 약속한대로 구현한다.
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
    // std::vector<int> v(5);  // C++ 표준 할당기 (std::allocator)
    // std::vector<int, MyAlloc<int> > v(5);   // 사용자가 만든 할당기 전달

    std::vector<int, debug_alloc<int> > v(5);
    v.resize(10);           //
}

// debuging 할 때, debug_alloc을 사용하면 메모리 할당 해지되는 것을 볼 수 있어서 이해하기 좋다.


