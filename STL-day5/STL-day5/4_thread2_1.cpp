//
//  4_thread2_1.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>

void foo(int n, double d)
{
    std::cout << "foo" << std::endl;
}

int main()
{
    std::thread t1(&foo, 3, 3.4);
    
    // 스레드를 생성한 후에는 반드시 아래 작업 중 하나를 해야합니다.
    t1.join();      // 스레드 종료를 대기
    t1.detach();    // 스레드 종료를 대기하지 않고, 더 이상 핸들도 필요없다.

}
