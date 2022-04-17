//
//  7_range.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 아래 코드의 원리는?
    for (auto e : v){
        std::cout << e << std::endl;
    }
    
    //-----------------------------------------------------
    // 위 코드를 보고 컴파일러가 만드는 코드
    // 핵심: for(auto e : "컨테이너")에서 "컨테이너의 begin, end()" 사용을 꼭 기억할 것
    auto  first = v.begin();
    auto  last = v.end();
    
    for (auto p = first; p != last; ++p){
        auto e = *p;
        // -----------------------------
        // 여기서부터 사용자 코드
        std::cout << e << std::endl;
    }
}

// 참고사이트
// 1. godbolt.org ==> C++(뿐 아니라 거의 모든 언어)를 어셈블리로 확인 가능
// 2. cppinsights.io ==> 다양한 C++ 문법의 원리를 보여주는 사이트ㄹ
