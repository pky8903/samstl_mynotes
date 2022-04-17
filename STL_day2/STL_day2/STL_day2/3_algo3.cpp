//
//  3_algo3.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.hpp"

// "알고리즘과 동일한 이름의 멤버 함수가 있다면 멤버 함수를 사용하라."
// 1. 멤버 함수에 해당하는 작업을 수행하는 함수가 있는지 찾고 멤버함수에 있으면 사용.
// 2 .멤버 함수에 없으면 "알고리즘(멤버가 아닌 일반 함수)" 에서 찾아서 사용
// 3. "알고리즘에도 없거나, 해당 알고리즘에 컨테이너 반복자를 보낼 수 없다면, 해당 컨테이너에서 해당 작업을 할 수 있는지 생각해보자.

int main()
{
    //std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
    std::list<int> v = { 1,2,3,1,2,3,1,2,3,1 };

    // 아래 방법은 동작은 하나 linked list에서는 성능이 좋지 않다.
//    auto p = std::remove(v.begin(), v.end(), 3); // 3이 나오면 3을 지우고 앞으로 당기고 알고리즘을 끝낸다.
//    show(v);
//
//    v.erase(p, v.end());
//    show(v);

    // list도 위 4줄이 실행되는 데는 문제는 없지만 성능이 좋지 않다.
    // 아래처럼 멤버 함수 remove를 사용하는 것이 효율적.
    v.remove(3);
    show(v);
    
    return 0;
}



















//
