//
//  debug_alloc.hpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#pragma once
#include <iostream>
#include <memory>

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
        printf("%d deallocated at %p\n", (int)sz, ptr);
    }
    
    // 위 2개 위에도 아래 3개가 있어야합니다.
    using value_type = T;
    debug_alloc() {}
    template<typename U> debug_alloc(const U&) {} // template 생성자
};
