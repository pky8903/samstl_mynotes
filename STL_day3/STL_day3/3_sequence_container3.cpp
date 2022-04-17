//
//  3_sequence_container3.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "show.hpp"

// capacity 개념
int main()
{
    std::vector<int> v(10, 0);

    v.resize(7); // 어떻게 구현했을까요 ?
    std::cout << v.size() << std::endl; // 7
    std::cout << v.capacity() << std::endl; // 10
    std::cout << &v[0] << std::endl;
    // those two lines tell us that 1) resize does not reallocate memories
    // 2) just changes a return value of size().
    
    v.push_back(20);    // 끝에 한 개 추가.
                        // 현재 상태는 메모리의 여유 공간이 있으므로
                        // 메모리 재할당 필요 없습니다.
                        // not expensive operation
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    std::cout << &v[0] << std::endl;
    
    v.shrink_to_fit(); // size == capacity가 되도록 해달라. size == capacity가 되도록 새로운 메모리를 할당받음.
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    std::cout << &v[0] << std::endl;
    
    v.push_back(3);     // 끝에 한 개 추가
                        // 여유 공간이 없으므로 메모리 재할당 필요
                        // expensive operation
    std::cout << v.size() << std::endl;     // 9
    std::cout << v.capacity() << std::endl; // ??? (16 in g++) (즉, 2배씩 확장)
    std::cout << &v[0] << std::endl;
    
    v.reserve(100); // 사이즈는 놔두고 메모리 capacity만 100으로 (잦은 메모리 재할당은 성능 저하의 원인이므로)
    std::cout << v.size() << std::endl; // 9
    std::cout << v.capacity() << std::endl; // 100
    std::cout << &v[0] << std::endl;

    // list에는 capacity 개념이 없습니다.
    // vector에만 있습니다.
    
    // 파이썬의 경우도 마찬가지임.
    
    // 아래 2개의 코드의 차이점
    // 항상 2번으로 해야함.
    // 1.
    std::vector<int> v1(100);   // 100개를 만들어놓고
    v1.resize(0);               // 일단 크기는 0으로 놓고 출발. size = 0, capacity = 100
    
    // 그런데 이 코드는 1. sizeof(int)*100의 메모리 할당
    //              2. int 타입이 아니라 사용자정의 타입이면 100번의 생성자 호출
    
    // 2.
    std::vector<int> v2;
    v2.reserve(100);            // size = 0, capacity = 100
                                // 1. 100개의 메모리만 할당됨.
                                //    int가 아닌 사용자 정의 타입이라도 생성자 호출 안됨.
}




