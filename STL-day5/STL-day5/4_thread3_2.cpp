//
//  4_thread3_2.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <thread>
#include <mutex>

class Machine
{
    int data1;
    int data2;
    std::mutex m;
public:
    void f1()
    {
        m.lock();
        data1 = 0;
        m.unlock();
    }
    void f2()
    {
        m.lock();
        data2 = 0;
        f1();       // 결국 동일스레드가 하나의 mutex에 lock이 2번 발생하게 됩니다
                    // 이 경우에는 recursive_mutex를 사용해야합니다.
        m.unlock();
    }
};

// C++11: mutex, condition_variable 제공.
//       thread local storage, call_once 제공.
// C++20: semaphore, latch, barrier 추가됨.
