//
//  3_chrono3_1.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <chrono>
using namespace std::literals; // min 등의 user define literal

int main()
{
    std::chrono::hours h(1); // 1시간
    std::chrono::seconds s(h); // 큰 단위 => 작은 단위에 넣기
                                // 데이타 손실 없음. ok..

    std::cout << s.count() << std::endl;

    s = s + 70s;  // 3670 초

    //-------------------------
//    std::chrono::minutes m(s); // 작은 단위 => 큰 단위에 넣기
                                // error.  캐스팅 필요
    std::chrono::minutes m =
        std::chrono::duration_cast<std::chrono::minutes>(s); // ok

    std::cout << m.count() << std::endl;

    
                    
}
