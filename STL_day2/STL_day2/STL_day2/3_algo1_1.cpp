#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 1. 용어
// 알고리즘의 일반벅인 의미: 문제를 해결하는 방법
// STL에서의 알고리즘: std::find() 같이 멤버함수가 아닌 일반 함수 템플릿을 의미

// 2. 헤더 파일
// #include <algorithm> // 대부분의 알고리즘
// #include <numeric> // 수치 연산 관련 알고리즘
// #include <memory>  // 메모리 관련 알고리즘

// 알고리즘 기본
int main()
{
    std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
    
    // 3. 사용법
    // 알고리즘(first, last, 추가 인자들.. )
    auto p = std::find( v.begin(), v.end(), 3);
    // auto p2 = std::find(v, 3); // 이렇게 하는게 더 편하지 않을까? 이렇게 하려고 했는데 기술적 문제로 만들 수 없었다. C++20부터는 가능해짐.
    // auto p1 = std::ranges::find(v, 3);
    
    return 0;
}



















//
