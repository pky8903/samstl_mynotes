//
//  6_CATEGORY1.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <forward_list> // single list C++11
#include <list>         // double list C++98

int main()
{
    std::forward_list<int> s1 = { 1,2,3 };

    std::list<int> s2 = { 1,2,3 };

    auto p1 = begin(s1);
    auto p2 = begin(s2);
    
    ++p1;
    //--p1; // error. forward list에선 next로 밖에 못간다.
    ++p2;
    --p2;

}

// 입력 vs 출력
// 입력반복자: =*p, ++
// 출력반복자: *p=, ++
// ---------------------------------- 위 2개는 멀티 패스 보장 안되고, 아래 3개는 멀티 패스 보장
// 전진형: =*p, ++         싱글리스트 반복자
// 양방향: =*p, ++, --     더블리스트 반복자
// 임의접근: =*p, ++, --, +, -, [] 연속된 메모리와 유사 (e.g. vector, deque)
