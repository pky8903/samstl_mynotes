//
//  nullptr.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

void fn (int n) { std::cout << "int" << std::endl; }
void fn (void* n) { std::cout << "void*" << std::endl; }
void goo(char* p) {}

int main()
{
    fn(0);          // 1번 call
    fn((void*) 0);  // 2번 call
    
#ifdef __cplusplus  // C++ 컴파일러인지 조사
#define NULL 0
#else
#define NULL (void*)0
#endif
    
    fn(NULL); // okay (위의 전처리를 하면 다시 int로 감)
    goo(NULL);  // void* => char*의 변환이 필요함.
                // C는 되는데 C++은 안됨
    
}
