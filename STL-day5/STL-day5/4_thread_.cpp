//
//  4_thread_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
// C++11부터 thread 관련 클래스 지원
#include <thread>
#include <chrono>

using namespace std::literals;

// this_thread namespace
// => 4개의 간단한 함수 제공

int main()
{
    std::cout << std::this_thread::get_id() << std::endl;
    
    std::this_thread::sleep_for(3s);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
//    std::this_thread::sleep_until(이때까지); // xtime 구조체 형태로 전달. 잘 안씀
    
//    std::this_thread::yield();  // 현재 스레드의 남은 실행시간 포기하고 다른 스레드 실행
}


