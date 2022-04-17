//
//  4_thread6_1.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>
#include <atomic>

// atomic

//int x = 0;

std::atomic<int> x = 0;

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
//        ++x;    // x.operator++()에서 "lock inc x" 와 유사한
                // lock-free 명령 수행
        x.fetch_add(1); // 이렇게 해도 동일
    }
}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&foo);
    std::thread t3(&foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
