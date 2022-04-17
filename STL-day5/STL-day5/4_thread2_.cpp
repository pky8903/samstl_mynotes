//
//  4_thread2_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>

void f1() {}

void foo(int n, double d)
{
    std::cout << "foo" << std::endl;
}

class Test
{
public:
    void goo(int n, double d)
    {
        std::cout << "goo" << std::endl;
    }
};

int main()
{
    // 핵심 1. 스레드를 생성하는 방법
    std::thread t1(&f1);    // 이 순간 스레드라 생성되어서 f1 함수 실행됩니다.delete                       // 별도의 start() 같은 함수는 필요 없습니다.
    
    // 핵심 2. 모든 종류의 함수를 스레드로 수행할 수 있습니다.
    //      인자의 형태에 제한이 없습니다.
    //      함수, 멤버 함수, 함수객체, 람다표현식 모두 가능
    std::thread t2(&foo, 3, 3.4);
    std::thread t3([](){ std::cout << "lambda" << std::endl; });
    
    Test test;
    std::thread t4(&Test::goo, &test, 3, 3.4);  // 객체 주소도 전달
    
    t4.join();

}

// 함수 이름에 대해서
// 일반 함수: 함수 이름은 함수 주소로 변환 가능하다. 즉, foo만 적어도 &foo 의미
// 멤버 함수: 함수 이름은 함수 주소로 변환 안된다.
//          멤버 함수의 주소가 필요할 때는 꼭 &Test::goo해야한다.
// 단, std::thread 사용시는 "함수 이름"만 해도 되고 "함수 주소"로 해도 된다.

