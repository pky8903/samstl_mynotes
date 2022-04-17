// debug_alloc.h
#pragma once
#include <cstdlib>
#include <iostream>

template<typename T> class debug_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		T* ptr = static_cast<T*>(malloc(sizeof(T) * sz));

		printf("%d allocated at %p\n", sz, ptr);
		return ptr;
	}
	void deallocate(T* ptr, std::size_t sz)
	{
		free(ptr);
		printf("%d deallocated at %p\n", sz, ptr);
	}

	// 위 2개위에도 아래 3개가 있어야 합니다.
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const U&) {} // 템플릿 생성자라는 함수
};

