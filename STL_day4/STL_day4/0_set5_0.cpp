//
//  0_set5_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include "show.h"
#include <set>

struct Compare
{
    bool operator()(int a, int b) const
    {
        return (a / 10) < (b / 10);
    }
};

int main()
{
    std::set<int, Compare> s;
    // 다음 중 실패는?
    s.insert(15);
    s.insert(25);
    s.insert(45);
    s.insert(35);
    s.insert(22);   // error. 10의 자리가 2인 요소가 이미 있다.
    show(s);

    // 아래 2개의 검색 결과는 어떻게 나올까요??
    // 아래 코드가 equality
    auto ret1 = std::find(s.begin(), s.end(), 12);  // ==
                                                    // 12가 없으므로 실패

    if (ret1 == s.end())
        std::cout << "실패" << std::endl;

    // 아래 코드가 equivalency
    auto ret2 = s.find(12);
    std::cout << *ret2 << std::endl;    // 15를 찾음
}
