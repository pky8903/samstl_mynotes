//
//  6_container_adapter3.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <list>
#include <vector>
#include <stack>
#include <queue> // queue, priority_queue
#include "show.hpp"

// STL에서 컨테이너 어댑터는 세개 있습니다.
// 1. vector
// 2. queue
// 3. priority queue_

int main()
{
    // 시험 문제!!
    
    // 다음 중 에러는?
    // stack: sequence의 한쪽 방향만 사용
    // queue: sequence의 양쪽 방향을 사용
    std::stack<int, std::list<int>>   s1;
    std::stack<int, std::vector<int>> s2;
    std::stack<int, std::deque<int>>  s3;

    std::queue<int, std::list<int>>   q1;
    std::queue<int, std::vector<int>> q2; // error. vector는 앞쪽 막힘.
    std::queue<int, std::deque<int>>  q3;
    
    q2.push(10); // 에러 아님. vector의 뒤쪽 (push_back)으로 넣기
    q2.front();  // 에러 아님. 제거가 아니므로
    q2.pop();    // 제거해야하는데 vector는 pop_front() 없음.
}
