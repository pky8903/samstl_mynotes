//
//  2_ref4_.cpp
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
    f1(v);  // call by value - f1이 실행되는 도중에 v가 파괴되어도 복사본으로 사용하게 되므로 언제나 안전
    
    f2(v);  // call by reference - f2가 실행되는 도중 v가 파괴되면 위험하다.
            // 그런데 멀티스레드가 아니므로 v가 파괴될 확률 없다.
}
