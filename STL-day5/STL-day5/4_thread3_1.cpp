//
//  4_thread3_1.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>
#include <mutex>

// 동기화 자원을 사용할 때는 직접 "lock/unlock"을 수행시
// 예외가 발생하는 "deadlock"의 가능성이 있습니다.

// 생성자/소멸자로 lock을 관리해야합니다.
// C++ 에서 예외가 발생하면 해당 지역 변수는 안전하게 소멸된다.
// 소멸자가 호출되면서 다른 대기하고 있던 thread가 안전하게 작업 진행 가능.

template<typename T>
struct lock_guard
{
    T& mtx;
    
    lock_guard(T& m) : mtx(m) { mtx.lock(); }
    ~lock_guard() : { mtx.unlock(); }
}

std::mutex m;

int shared_data = 10;   // static memory에 놓이고 모든 쓰레드가 공유함

void foo()
{
//    m.lock();
    lock_guard<std::mutex> g(m);    // 생성자를 통해 lock()
    // 공유 자원 사용
    shared_data = 200;
//    m.unlock();
} // 다 쓰고 소멸자가 불리면서 unlock()

int main()
{
    std::thread t1(&foo);
    std::thread t2(&foo);

    t1.join();
    t2.join();
}
