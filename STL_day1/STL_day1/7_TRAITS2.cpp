//
//  7_TRAITS2.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <algorithm>

/*
int sum (int* first, int* last){
    int s = 0;
    
    while (first != last){
        s += *first;
        ++first;
    }
    
    return s;
}
*/

// raw array뿐 아니라 STL container도 가능한 sum 만들기
// "T"가 반복자일 때, "T::value_type"은 반복자가 가리키는 타입.
template<typename T>
typename T::value_type sum (T first, T last){
    typename T::value_type s = 0;
    
    while (first != last){
        s += *first;
        ++first;
    }
    
    return s;
}


int main()
{
    //int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

    //int n = sum(x, x + 10);

    std::list<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sum(s.begin(), s.end());
    
    std::cout << n << std::endl; // 55

    
}
