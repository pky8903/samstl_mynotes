//
//  1_bind_function_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int a, int& b) { b = 100; }

int main()
{
    std::function<void(int)> f;

    int n = 0;

//    f = std::bind(&foo, _1, n);     // 이 한줄을 생각 해 봅시다.
                                    // foo의 두 번째 인자로
                                    // 1. "n" 자체를 참조로 보관 (이땐 화면에 100이 출력)
                                    // 2. 0을 보관 (이땐 화면에 0이 출력)
                                    // 답: 0을 보관 (화면에 0이 출력)

    f = std::bind(&foo, _1, std::ref(n));   // n을 참조로 보관해달라.
                                            // "std::ref(n)" -> multithreading에서 중요 (원리가 중요)
    
    f(0);  // foo(0, n)

    std::cout << n << std::endl; // 결과 예측해 보세요
}
