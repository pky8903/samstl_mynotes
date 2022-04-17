//
//  4_thread7_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// reordering: 컴파일러가 최적화하면서 코드의 순서를 변경해놓는 현상

#include <atomic>

int a = 0;
int b = 0;

// foo, goo 다른 스레드가 실행한다.
void foo()
{
//    a = b + 1;  // b를 캐쉬에 올려두고 1 올리고, a도 캐쉬에 올리고
//    b = 1;      // 다시 b를 캐쉬에 올리는 것이라 생각하는데!
                // 컴파일러가 최적화하면서 순서를 바꾼다.
                // b에 1을 올린 값은 레지스터에 있으니까
                // 아래 줄을 먼저 수행 후에
                // 다시 a를 캐쉬에 올려서 계산을 수행한다.
                // 이런것 때문에 멀티스레딩에서는 a는 반드시 1임을 보장할 수가 없다.
    
    a = b + 1;
    std::atomic_thread_fence(std::memory_order_seq_cst); // 위 코드는 이 펜스를 넘을 수 없다.
    b = 1;
}

void goo()
{
    if (b == 1)
    {
        // a는 반드시 1일까요?
    }
}

int main()
{
}
