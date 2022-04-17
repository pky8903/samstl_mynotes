//
//  3_chrono3_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;

int main()
{
    // 1. predefined typedef
    hours         h(1);     // typedef duration<int, ratio<3600,1>> hours;
    minutes      m  = h;
    seconds      s  = h;
    milliseconds ms = h;
    microseconds us = h;
    nanoseconds  ns = h;
    
    // 앞으로 "3초"가 필요하면
    std::chrono::seconds sec(3);

    std::cout << h.count() << std::endl;
    std::cout << m.count() << std::endl;
    std::cout << s.count() << std::endl;
    std::cout << ms.count() << std::endl;
    std::cout << us.count() << std::endl;
    std::cout << ns.count() << std::endl;

    // 2. literals( h, min, s, ms, us, ns )
    auto s2 = 10s;      // seconds operator""s(10)이라는 함수가 호출되는 문법

    seconds sec = 1min;

    sec = 1min + 3s;
    sec += 40s;
    std::cout << sec.count() << std::endl;

    seconds sec2 = 1min + 3s;
    std::cout << sec2.count() << std::endl;

    
    // 결론 어떤 함수에 10초를 보내고 싶을때
//    foo (std::chrono::seconds(10)); // seconds 객체를 직접 만들거나
//    foo (10s);                      // 이렇게 해도 됩니다.
//    3s, 3min 등을 사용하려면
//    #include <chrono>                // 헤더
//    using namespace std::literals;    // namespace

}
