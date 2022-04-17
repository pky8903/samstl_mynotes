//
//  2_STL_ALGORITHM1.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>

// 1. C++ standard function
char* xstrchr(char* s, int c)
{
    while (*s != 0 && *s != c)
        ++s;
    return *s == 0 ? 0 : s;
}

// 2. Generalization of searching ranges: substring can be searched --> more generic
// linear search within [first, last)
char* xstrchr(char* first, char* last, int c)
{
    while (first != last && *first != c)
        ++first;
    return first == last ? nullptr : first;
}

// 3. Generalization of types of seraching targets
template <typename T>
T* xfind(T* first, T* last, T c)
{
    while (first != last && *first != c)
        ++first;
    return first == last ? nullptr : first;
}
// problem of the above template function:
// 1. for the case of xfind(type double*, type doupble, type float)
// compiler cannot determine a type from the above context in the template function.
// 2. "T*": we should use "raw pointer". We cannot use a smart pointer.

// 4. More generic!!
template <typename T1, typename T2>
T1 xfind_generic(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
        ++first;
    return first == last ? nullptr : first;
}

// 5. 검색 실패 시 nullptr 대신 last 반환
// 1. find 구현 자체도 조금 빨라진다.
// 2. 활용도가 좋다. find 실패시 반환값은 다음 검색 구간의 시작이 된다.
// 3. 유연성도 좋다. 스마트 포인터 사용시 모든 스마트 포인터가 nullptr과 호환될 것이라는 보장이 없다.
template <typename T1, typename T2>
T1 xfind_generic2(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
        ++first;
    return first;
}
// find summary:
// searching range : [first, last) 사이의 임의 타입의 배열, last는 검색 대상 아님.
// 구간의 표현: 반드시 포인터일 필요 없다. 단, *, !=, ++ 가 가능한 타입
// 구간의 이동: 전위형 ++ 연산자 사용
// 실패의 반환: last 반환 - "past the end"

template <typename T>
void print(T* value){
    if (value == nullptr) // use "nullptr" rather than 0, which is better in C++11.
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << *value << std::endl;
}

int main()
{
    char s[] = "abcdefgh";
    char* p = xfind_generic(s, s+4, 'e');
    print(p);
    
    double x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // double* p2 = xfind(x, x+10, 5): build 실패: compiler가 type 결정을 못함. Problem 1 of step 3.
    double* p2 = xfind_generic(x, x+10, 5); // 비교를 위해 제일 11번째 메모리를 사용하는 것은 언어에서 보장을 해준다.
    

    if (p2 == x+10) // use "nullptr" rather than 0, which is better in C++11
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << *p2 << std::endl;

    
}
