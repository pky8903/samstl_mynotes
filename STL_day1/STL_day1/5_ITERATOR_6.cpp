//
//  5_ITERATOR_6.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    int y[5] = { 0, 0, 0, 0, 0 };
   
    std::list<int> s2 = { 1, 2, 3, 4, 5 };
    
    // x의 모든 요소를 y로 복사하고 싶을 때
    // 1. for loop
    //for (int i = 0; i < 5; ++i){
    //    y[i] = x[i];
    //}
    
    // 2. range for
    //int i = 0;
    //for (auto e : x){
    //    y[i++] = e;
    //}
    
    // 3. copy algorithm
    std::copy(x, x+5, y);
    
    std::for_each(y, y+5, [](int a){ std::cout << a << std::endl; });
    
    
    std::copy(s2.rbegin(), s2.rend(), y); // container to array? 컨테이너건, 배열이건, 결국 반복자로 작업하므로 동일하게 사용.
    // 반복자란: "반복자처럼 동작하는 모든 것은 반복자이다." ++로 이동 가능하고, *로 요소 접근이 가능하면 반복자이다.
    // 1. slist_iterator처럼 클래스로 만든 것도 반복자.
    // 2. int* 처럼 raw_pointer도 반복자.
 
    for (auto e : y){
        std::cout << e << ", ";
    }

}
