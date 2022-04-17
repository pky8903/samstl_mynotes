//
//  6_optional_2.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// 6_optional
#include <iostream>
#include <optional>

// 실패의 가능성이 있는 함수를 만들 떄
// 1. 예외를 사용하거나
// 2. optional로 하자
std::optional<int> foo()
{
    if (1)
    {
        return std::nulloopt;
    }
    
    return 100;
}
int main()
{
    auto ret = foo();
    if (ret) // ret != std::nullop
    {
        int n = *ret;
    }

}
