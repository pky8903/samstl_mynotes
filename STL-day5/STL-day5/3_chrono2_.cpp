//
//  3_chrono2_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// duration 정의: 특정 단위의 갯수(tick count)를 표현하는 자료구조
//              10초 -> 1초의 10개
//                  -> 1/1000초의 10000개

#include <iostream>
#include <ratio>

int main()
{
    // 1. duration 사용
    std::chrono::duration<int, std::ratio<1, 100>>  d1(2); // 1/100 * 2
    std::chrono::duration<int, std::ratio<1, 1000>> d2(d1);
    
    std::cout << d2.count() << std::endl;   // 20
    
    // 2. 이제 duration으로 단위를 나타내는 타입 만들면 됩니다.
    using namespace std::chrono;
    using Meter         = duration<int, std::ratio<1, 1>>;
    using CentiMeter    = duration<int, std::ratio<1, 100>>;
//    using KiloMeter     = duration<int, std::ratio<1000, 1>>;
    using KiloMeter     = duration<int, std::kilo>;
    
    KiloMeter km(3);   // 3 km
    CentiMeter cm(km);
    
    std::cout << cm.count() << std::endl;

    // 3. 시간을 나타내는 단위 - 이미 표준에 아래처럼 되어있음.
//    using seconds   = duration<int,  std::ratio<1, 1>>;
//    using minutes   = duration<int,  std::ratio<60, 1>>;
//    using hours     = duration<int,  std::ratio<3600, 1>>;
    
}
