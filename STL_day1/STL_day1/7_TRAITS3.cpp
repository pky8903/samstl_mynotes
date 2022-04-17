//
//  7_TRAITS3.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <vector>
#include <list>

// STL에서 반복자는 크게 2가지 형태로 볼 수 있다.
// 1. class로 만드는 객체형 반복자
//  => 객체이므로 T::value_type이 존재함
// 2. raw poointer (int* double* 등)
//  => int*::value_type 등이 존재하지 않는다.
// 위 두가지 차이점때문에 sum같은 함수를 generic하게 만들기 어렵다.

template<typename T>
struct iterator_traits
{
    using value_type = typename T::value_type;
};

template<>
struct iterator_traits<T*>
{
    using value_type = T;
};

template<typename T>
typename iterator_traits<T>::value_type sum (T first, T last){
    //typename iterator_traits<T>::value_type s = 0;
    typename std::iterator_traits<T>::value_type s = 0;
    
    while (first != last){
        s += *first;
        ++first;
    }
    
    return s;
}

int main()
{
    std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

    int n1 = sum(x, x + 10);
    int n2 = sum(std::begin(s), std::end(s));
    
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
}
