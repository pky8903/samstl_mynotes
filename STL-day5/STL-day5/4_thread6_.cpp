//
//  4_thread6.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>

// atomic

int x = 0;

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
//        x = x + 1;    // 3000000이 안된다. assembly 언어에서 확인 가능. x = x + 1 과정 중에 다른 스레드가 들어옴.
//        __asm
//        {
//          mov eax, x
//          add eax, 1
//          mov x, eax
//        }
        
//        m.lock();     // 이렇게 하면 해결은 되지만 너무 무겁다.
//        x = x + 1;
//        m.unlock();
        
//        1 증가하기 위한 어셈을 다르게 해봅시다.
//        inc: 실행 중 context switching이 발생하지 않을 것을 보장합니다.
//          그런데, CPU 자체가 여러개인 경우에는 1 증가가 보장되지 않습니다.
//        lock prefix: 다중 cpu에서 특정 메모리를 동시 접근할 수 없게하는 Intel opcode
        __asm // g++는 코드가 조금 다르다.
        {
            lock inc x
        }
        // lock free: OS의 동기화 도구를 사용하지 않고 CPU 명령만 가지고, 동기화를 구현하는 기술.
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
