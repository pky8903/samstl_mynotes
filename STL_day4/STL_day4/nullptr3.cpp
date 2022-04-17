//
//  nullptr3.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

// nullptr의 역사
// 1. boost 라이브러리에서 아래처럼 만들어서 제공했습니다.
// 2. C++11 에서 표준에 추가되면서는 nullptr 을 키워드로 만들었습니다.

struct xnullptr_t
{
    template<typename T>
    operator T* () const { return 0; }
};
// 결국 nullptr은 포인터타입으로만 변환 가능한데..0으로 채워줍니다.
xnullptr_t xnullptr;

int main()
{
//    int n = xnullptr;   // error
    int* p1 = xnullptr; // ok
    char* p2 = xnullptr;    // ok
 
    
    hoo(0); // ok 리터럴 0은 포인터로 변환 가능
    int n = 0;
    hoo(n); // error. 0으로 초기화된 int 변수는 error
    hoo((int) 0);
}
