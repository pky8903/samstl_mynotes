//
//  5_functor6.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>

// 1. 일반 함수는 자신만의 타입이 없다.
//    signature (리턴 타입과 파라미터)가 동일한 모든 함수는 같은 타입이다. (중요) (Note: 함수포인터를 보아도 알 수 있다).
// 2. functor는 자신만의 타입이 있다.
//    signature (리턴 타입과 파라미터)가 동일해도 모든 functor는 다른 타입이다.


struct Less
{
    inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
    inline bool operator()(int a, int b) { return a > b; }
};

int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

    Less    f1; f1(1, 2); // f1 f2는 signature는 동일하지만 다른 타입이다. functor는 자신만의 타입이 있다.
    Greater f2; f2(1, 2);
}
