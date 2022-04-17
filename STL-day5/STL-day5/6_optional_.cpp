//
//  6_optional_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// 6_optional
#include <iostream>
#include <optional>

int foo()
{
    // 실패를 알리고 싶다.
    // 1. 예외로 전달한다.
    // 2. optional<int> 사용
    return 100; // 성공
}
int main()
{
    int ret = foo();
    
    int n1 = 0;     // n1은 정수 값을 가집니다.
    
//    std::optional<int> n2 = 10; // n2는 정수값 + 값없음(NULL)의 상태를 가질 수 있습니다.
    std::optional<int> n2 = std::nullopt;
    
    if ( n2 )
    {
        std::cout << "값 있음 : " << *n2 << std::endl;
    }
    else
    {
        std::cout << "값 없음 : " << std::endl;
    }
}
