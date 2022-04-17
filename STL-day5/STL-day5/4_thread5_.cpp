//
//  4_thread5_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

int foo()
{
    std::this_thread::sleep_for(5s);
    return 100;
}

int main()
{
//  int ret = foo();    // 스레드 수행이 아닌, 주 스레드가 함수 호출
    
    // foo 함수를 스레드로 실행하고, 결과를 future 객체로 반환해달라.
    std::future<int> ft = std::async(std::launch::async, &foo);
    
    std::cout << "main 계속 실행" << std::endl;
    
    int result = ft.get();  // 스레드 함수(foo)가 아직 return 하지 않은 경우는
                            // 대기
}
