//
//  4_thread3_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
//std::recursive_mutex m; // 2번 이상 lock 가능
//std::shared_mutex m;    // 쓰는 동안엔 다른 thread에서 못읽게 하는데 읽게는 허용

// std::timed_mutex : 특정 시간이 지나면 unlock()
// std::timed_recursive_mutex
// std::timed_shared_mutex

int shared_data = 10;   // static memory에 놓이고 모든 쓰레드가 공유함

void foo()
{
    m.lock();
    // 공유 자원 사용
    shared_data = 200;
    m.unlock();
}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&foo);

    t1.join();
    t2.join();
}
