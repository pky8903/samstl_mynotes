//
//  1_map1.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

// 6_map1
#include "show.h"

#include <map>

// map : pair를 저장하는 set, key 값으로 value를 저장
int main()
{
    std::map<std::string, std::string> m;

    // 1. 요소 넣기
    // 1.1. pair 만들어서 넣기‚
    std::pair<std::string, std::string> p1("mon", "월요일");
    m.insert(p1);

    // 1.2. make_pair
    m.insert(std::make_pair("tue", "화요일"));

    // 1.3. emplace
    m.emplace("wed", "수요일");

    // 1.4. [] 연산자 사용
    m["sun"] = "일요일";
    
    //------------------------

    // 2. 반복자에 대해서
    // 반복자는 "요소의 포인터 역할"을 하는데,
    // map의 요소는 "std::pair"입니다.
    // 따라서, map의 반복자는 "pair의 포인터" 처럼 생각하면 된다.
    auto p2 = m.begin();    // pair의 pointer
    std::cout << p2->first << std::endl;
    std::cout << p2->second << std::endl;
    
    
    // 3. [] 연산자에 대해서
    std::string s1 = m["sun"]; // 맵 안에 sun 키가 있으므로 s2는 "일요일"
    std::string s2 = m["sat"]; // 현재 맵 안에 "sat" 키는 없음. 이 순간 {"sat", ""}의 쌍으로 항목이 추가됨.
    
    // 그래서, 키 값이 있는지 검색할 때는 아래와 같이 하면 안됨.
    if (m["sun"] != "") {}     // 가능은 하지만, 이 순간 키 값이 만들어지게 됩니다.
                                // 의도는 단순한 조사였는데, 이 코드는 키값이 생성된다.
    
    // 조사는 아래 코드로
    auto ret = m.find("sun");
    if (ret == m.end()) {} // "sun"이 없는 경우.
    
    // c++20에서는 아래 맴버 함수가 추가되었음
//    if (m.contains("sun")) {}
    
    // 반복자에 대해서
    auto p = m.find("wed"); // find(≈∞∞™)

}
