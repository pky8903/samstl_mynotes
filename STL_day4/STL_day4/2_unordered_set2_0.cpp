//
//  3_unordered_set2_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <unordered_set>
#include "show.h"

int main()
{
    // set                  : tree를 사용한 set
    // unordered_set        : hash를 사용한 set
    std::unordered_set<int> s;

    // set와 unorderd_set의 사용법은 거의 동일합니다.
    // 그런데 동작 원리는 완전히 다릅니다.
    s.insert(10);   // c.f. set: root 요소와 비교하여 left/right 자식으로 삽입
                    // unordered_set: 30을 hash 함수로 보내서 hash 값을 가지고 보관
    s.insert(35);
    s.insert(20);
    s.insert(25);

    auto p = s.find(20);  // hash 함수를 사용해서 검색

    std::cout << *p << std::endl;

    show(s);
}
