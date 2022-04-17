//
//  9_lambda4.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>

int main()
{
    int v1 = 10, v2 = 10;
    
    // 1. 람다표현식에서 지역변수를 사용하려면 캡쳐해야합니다.
    auto f1 = [v1, v2](int a) { return a + v1 + v2; };
    
    // 2. 값으로 캡쳐하면 읽기만 가능하다.
    //auto f2 = [v1](int a) { v1 = a; }; // error
    
    // 3. 변경가능하게 하려면 참조로 캡쳐
    auto f3 = [&v1](int a) { v1 = a; };
    
    f3(100); // v1 = 100;
    
    std::cout << v1 << std::endl;
}
