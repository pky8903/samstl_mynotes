//
//  nullptr2.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

void fn (int n) { std::cout << "int" << std::endl; }
void fn (void* n) { std::cout << "void*" << std::endl; }
void goo(char* p) { std::cout << "char*" << std::endl; }

// 0은 정수인데, 포인터 초기화에도 사용된다.
// 그런데 이 사실이 가끔 혼란을 일으킨다 (nullptr1.cpp 참고)
// 포인터 초기화에 "0"을 사용하지 말고 "포인터 0"을 만들자.

struct xnullptr_t
{
    // xnullptr_t => void*로 변환이 필요할때마다 아래 함수 호출
//    operator void* () { return 0; }
//    operator char* () { return 0; }
    
    template<typename T>
    operator T* () const { return 0; }
};
// 결국 nullptr은 포인터타입으로만 변환 가능한데..0으로 채워줍니다.
xnullptr_t xnullptr;

int main()
{
    fn(0);
    fn(xnullptr);   //xnullptr => void* 변환 가능하면 된다.
                    //xnullptr.operator void*() 를 찾게 된다. (변환 연산자)
    goo(xnullptr);
    
}
