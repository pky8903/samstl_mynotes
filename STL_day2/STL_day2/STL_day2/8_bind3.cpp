//
//  8_bind3.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <algorithm>
#include <functional>


int main()
{
    // c++ 표준에 modulus 라는 함수 객체가 이미 존재합니다.
    // <functional> 헤더 (람다 치환이 안되었을때 functional을 썼었음)
    std::modulus<int> m;
    
    int n = m(10, 3);
    
    std::cout << n << std::endl;
    
    int x[5] = { 9, 9,2,4,3};

    // 3의 배수가 아닌 것을 찾고 싶다.!
    // auto p = std::find_if ( x, x+5, m); // m은 인자 2개 받는 이항함수 객체라 바로 넣으면 안됨.
    // find_if는 단항함수 객체를 요구함
    auto p = std:: find_if(x, x+5, std::bind(m, std::placeholders::_1, 3));
    std::cout << *p << std::endl;
    
    // 알고리즘 사용시 위처럼 bind 함수로 전달하는 방법도 예전에는 많이 사용하였으나
    // 그런데 요즘은 람다표현식 권장.
}


