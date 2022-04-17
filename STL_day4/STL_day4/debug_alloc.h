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

	// �� 2�������� �Ʒ� 3���� �־�� �մϴ�.
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const U&) {} // ���ø� �����ڶ�� �Լ�
};

