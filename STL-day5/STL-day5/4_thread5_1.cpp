//
//  4_thread_5_1.cpp
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
    std::cout << "foo 실행" << std::endl;
    std::this_thread::sleep_for(5s);
    return 100;
}

int main()
{
    // std::launch::async       : 비동기(새로운 스레드)로 함수를 실행해달라
    // std::launch::deferred    : 지연실행, 결과가 필요할 때 실행해달라.
    //                           새로운 스레드가 아닌 주 스레드가 호출
    
    std::future<int> ft = std::async(std::launch::async, &foo);
//    std::future<int> ft = std::async(std::launch::deferred, &foo);
    
    std::cout << "main 계속 실행" << std::endl;
    
    std::this_thread::sleep_for(2s);
    
    int result = ft.get();
    
    std::cout << "결과: " << result << std::endl;
}
