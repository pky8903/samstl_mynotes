//
//  7_TRAITS4.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <vector>
#include <iostream>

// function argument 관례:
// 반복자: call by value를 주로 사용 (크기가 크지 않은 타입)
// 컨테이너: const reference 또는 reference 사용

template<typename T>
void f1(T p)
{
    // T는 객체형 반복자 또는 raw pointer
    // 둘 다 사용법이 동일하므로 *p 등으로 요소 접근 가능
    auto n = *p;
    ++p;
    
    // typename T::value_type n2; // raw pointer 못받음
    typename std::iterator_traits<T>::value_type n2; // raw pointer, iterator 다 됨
    
    // C++20 에서 새로운 표기법. typename도 필요없음.
    // std::iter_value_t<T> n3;
}

template<typename T>
void f2(T& c)
{
    //  T는 STL container이거나, raw array.
    // std::begin() 등으로 반복자를 꺼내면 안전함.
    
    // auto p1 = c.begin(); // c가 배열이면 안됨.
    auto p1 = std::begin(c); // 모두 가능
    
    // 컨테이너가 저장하는 타입을 알고싶다.
    // typename T::value_type n; // T가 STL container일때만 가능. T가 array면 error.
    // iterator_traits처럼 컨테이너와 배열에 상관없이 요소의 타입을 구하는 방법은? c++ 20에서야 도입됨.
    // std::ranges::range_value_t<T> n;
}

int main()
{
    int x[4] = {1, 2, 3, 4};
    std::vector<int> v = { 1, 2, 3, 4 };
    
    f1(v.begin());
    f1(x);
}
