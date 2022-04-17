//
//  6_container_adapter4.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <stack>
#include <queue> // queue, priority_queue
#include <iostream>
#include "show.hpp"

int main()
{
    // 우선순위 큐: 요소를 꺼날 때 우선순위가 가장 높은 요소가 나오게 된다.
    // priority_queue<저장타입, 내부컨테이너, 우선순위를 계산할 때 사용할 함수 객체 타입>"
    
//    std::priority_queue<int> pq;
    std::priority_queue<int, std::vector<int>, std::less<int> > pq;
    
    pq.push(10);
    pq.push(-10);
    pq.push(-20);
    pq.push(20);
    pq.push(15);

    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;

}
