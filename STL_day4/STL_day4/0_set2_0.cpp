//
//  0_set2_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <functional>
#include "show.h"

// set: 집합(교집합, 합집합 등) 관련 연산 제공
#include <set> // Red Black Tree로 구현

int main()
{
//    std::set<int>  s;
    std::set<int, std::greater<int> > s;

    s.insert(20);
    s.insert(30);
    s.insert(15);
    s.insert(5);
    s.insert(40);
    
    // 핵심 1. 요소의 중복을 허용하지 않는다.
    std::pair<std::set<int>::iterator, bool> ret = s.insert(15); // 실패
//    auto ret = s.insert(15); // 요즘은 그냥 auto로 받는다.

    if (ret.second == false)
        std::cout << "fail" << std::endl;
    else
        std::cout << "ok " << std::endl;
    
    // 핵심 2. 요소 삽입은 insert(또는 emplace) 만 가능하다.
    //      항상 자료구조의 특징을 잘 생각해야한다.
//    s.push_front(37); // 자료구조가 tree기 때문에 root로부터 비교밖에 안되고, 따라서 push_front()를 할 수 없다.
    
    // 핵심 3. 반복자로는 읽기만 가능하다.
    auto p1 = s.begin();
//    *p1 = 100;  // error
    
    // 핵심 4. 자료구조 특성에 맞는 함수를 사용하기.
    auto ret1 = std::find(s.begin(), s.end(), 15); // 에러는 없고 검색도 잘 된다. 하지만 선형검색. 내부 트리 알고리즘 (이진 검색)을 사용할 수 있는데 선형검색을 할 필요가 있을까? 비효율
    std::cout << *ret1 << std::endl;
    
    auto ret2 = s.find(15); // binary search
    std::cout << *ret2 << std::endl;
    
    // 알고리즘과 동일한 이름의 멤버 함수가 있으면 멤버 함수를 사용해라!
    
    show(s);
    
}
