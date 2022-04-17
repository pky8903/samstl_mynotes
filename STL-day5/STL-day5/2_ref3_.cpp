//
//  2_ref3_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>

void foo(int& a) { a = 200; }

template<typename F, typename T> void bind_call(F f, T arg) // arg의 복사본을 받으니 n은 바뀌지 않는다
{
    f(arg);
}
int main()
{
    int n = 10;

    foo(n);    // 직접 전달, n은 200으로 변경됩니다.

//    bind_call(foo, n);    // n의 복사본을 전달하니 n은 바뀌지 않는다.
//    bind_call(foo, &n);     // 값이 아닌 메모리 주소를 보냅니다.
                            // foo에서 참조를 argument로 받는데, 포인터가 참조로 변환이 될 수 없다.
    
    // reference_wrapper의 의미: 객체의 주소를 보관하는데, 참조로도 변환 가능한 도구
    std::reference_wrapper<int> r(n);   // 1. r은 n의 주소를 보관
                                        // 2. 참조로 변환 가능
    
    bind_call(foo, r);
    
    bind_call(foo, std::ref(n));    // ref(n)이 결국 reference_wrapper의 도움함수입니다.
                                    // 위 두 줄과 동일한 의미

    std::cout << n << std::endl;
}
