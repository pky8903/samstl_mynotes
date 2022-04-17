//
//  3_linear_container.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

// Sequence container, 선형 컨테이너
// => 요소가 순서를 가지고 한 줄로 놓여있는 컨테이너
// => 5개가 있습니다.
// => "메모리 구조"와 "반복자의 종류"를 알아두세요.
// C++98 에서 3개
#include <vector>  // 연속된 메모리, 임의 접근 반복자            // 순환은 빠르다. but 삽입 삭제가 많을 땐 성능 저하
#include <deque>   // 연속된 메모리와 유사, 임의 접근 반복자       //
#include <list>    // 떨어진 메모리, 양방향 반복자               // 삽입 삭제가 빠르다.

// C++11 에서 2개
#include <forward_list> // 전진형 반복자
#include <array>        // 임의접근 반복자

#include "show.hpp"

int main()
{
//    std::vector<int> c= { 1, 2, 3 };
    std::list<int> c = { 1,2,3 };
    
    // 핵심 1. sequence 컨테이너는 사용법이 유사합니다.
    c.push_back(10);
    c.pop_back(); // vector든 list든 똑같이 사용 가능.

    // 핵심 2. 사용법에 차이가 있다면 "의도적으로" 그렇게 설계한 것.
    // => vector는 앞쪽으로 삽입/삭제가 안됩니다.
    // => 앞에 넣고 싶다면 "다른 컨테이너"를 사용하라는 의도
    c.push_front(5); // vector에서 에러.
    c.pop_front();   // vector에서 에러.
    
    // 핵심 3. [] 연산은 list는 사용할 수 없습니다.
    c[0] = 10; // vector, deque는 가능. list는 안됨.
    
    // 핵심 4. 모든 요소 순회는 range_for 혹은 반복자 사용
    for (auto e : c) // 모든 컨테이너 가능
    {
    }
    
    auto p1 = c.begin();    // std::begin(c)
    
    while (p1 != c.end())
    {
        ++p1;
    }
    
    // 핵심 5.
    // 전방 삽입은 필요 없고, []가 필요. 삽입 삭제는 적다: vector
    // 전방 삽입은 필요하고, []가 필요. 삽입 삭제는 적다: deque
    // []는 필요 없고, 삽입 삭제가 많다: list
    
    // cache에 한번에 올라올 수 있는 선형 컨테이너는 vector. vector가 빠르다.

}
