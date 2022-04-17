//
//  2_ref5_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <thread>
#include <functional>

void f1(int n) { n = 100; }
void f2(int& n) { n = 100; }

int main()
{
    int v = 10;
    
    std::thread t1(f1, v);      // f1을 스레드로 실행해달라
                                // 인자를 v로 보내달라
    t1.join();
    
//    std::thread t2(f2, v);      // v가 참조이므로 컴파일 에러를 낸다
    // 결국 v는 직접 f2로 전달되는 것이 아니라
    // v => thread 생성자 => f2로 전달되게 되는데
    // thread 생성자가 call by value로 되어있다.
    // call by value로 된 곳에 "참조로 보내려면 std::ref()"를 사용해야한다.
    std::thread t2(f2, std::ref(v));    // okay
                                        // 대신 책임은 작성자에게 있다
    t2.join();
}
