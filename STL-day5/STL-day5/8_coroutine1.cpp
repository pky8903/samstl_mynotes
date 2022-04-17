//
//  8_coroutine1.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <coroutine> // C++20 coroutine기술


// C++ 에서 코루틴을 사용하기 위해서는 "C++ 표준문서가 제시하는 조건을 지켜야 합니다."
// 1. 사용자 정의 타입을 반환해야 한다.
// 2. 반환 타입에 사용되는 객체안에는 "promise_type" 이라는 멤버 타입이 있어야 한다.

// github.com/codenuri/cpp20

struct Task
{
    struct promise_type
    {
        // 약속된 5개의 함수를 제공해야 한다.
        //
    };
};

Task foo()
{
    //--------------------
    // 컴파일러가 corotuine 관련 코드를 생성하는데..
    // Task 안에 있는 promise_type 의 객체를 생성해서
    // 특정 이벤트 상황에서 약속된 함수를 호출해 줄께!!
    //------------------------------------
    std::cout << "foo 1" << std::endl;
    co_await std::suspend_always{};    // 호출자에게 돌아가라는 것

    std::cout << "foo 2" << std::endl;
    co_await std::suspend_always{};    // 호출자에게 돌아가라는 것
}

int main()
{
    auto coro = foo();
    
    std::cout << "main 1" << std::endl;
    coro.resume();
    std::cout << "main 2" << std::endl;
    coro.resume();
}
