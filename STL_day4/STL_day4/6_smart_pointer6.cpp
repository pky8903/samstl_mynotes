//
//  6_smart_poineter6.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
    // 삭제자 변경
    std::shared_ptr<int> sp1( new int ); // ok

//    std::shared_ptr<int> sp2( (int*)malloc(sizeof(int)) ) ; // bug..sp2의 소멸자는
                                                            // delete 수행
                                                            //
    // 핵심 1. 삭제자를 변경하려면 shared_ptr 생성자의 2번째 인자로 전달
    std::shared_ptr<int> sp2((int*)malloc(sizeof(int)), foo);// ok. 삭제자 변경
//    std::shared_ptr<int> sp2((int*)malloc(sizeof(int)), free);
//    std::shared_ptr<int> sp2((int*)malloc(sizeof(int)), [](int* p) { free(p); });


    // 핵심 2. new [] 로 할당한 경우
    std::shared_ptr<int> sp3(new int[10]); // bug, "delete[]" 해야 하는데
                                            // delete 하게 된다.

    // 배열 할당의 경우 아래 처럼 삭제자를 변경해야 합니다.
    std::shared_ptr<int> sp4(new int[10], [](int* p) { delete[] p; }); // ok
    
    // C++17 부터는 아래 처럼 하면 됩니다.
    std::shared_ptr<int[]> sp5(new int[10]);

    // 그런데, 생각해볼 문제,  new int[10] 이 필요하면 ??
    // 왜.. 스마트포인터로 관리하는가 ??
    // vector가 있는데.
    std::vector<int> v(10); // 결국 new int[10] 아닐까 ?
    // 라는 철학으로
    // 한개 객체는 shared_ptr 로 관리하고
    // 여러 객체는 vector 로 하자..
    // 고 최초에는 생각했다.
}
