//
//  3_sequence_container2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "show.hpp"

int main()
{
    // array vs vector
    // array    : 크게 변경 불가. 지역 변수라면 stack
    // vector   : 크기 변경이 가능(동적 배열), v가 지역변수라도, 요소 자체는 힙에 생성.
    
    int x[5];
    std::vector<int> v(5);  //  객체 자체는 stack에 있더라도 data는 heap에 보관.
    v.resize(10);           //  크기 변경
    
    // 1. 생성
    std::vector<int> v1;        // 크기 0
    std::vector<int> v2(10);    // 크기 10, 0으로 초기화
    std::vector<int> v3(10, 3); // 크기 10, 3으로 초기화
    std::vector<int> v4(v3);    // v3와 동일하게
//    std::vector<int> v5{ 10, 3 };
    std::vector<int> v5 = { 10, 3 };    // 위 코드와 동일
    std::vector<int> v6 = { 1,2,3 };
    

    // 2. 삽입 - 앞, 뒤, 임의
    v.push_back(10);
//    v.push_front(10); vector는 전방 삽입 안됨.
    auto p = v.begin();
    ++p;
    v.insert(p, 20);    // v.insert(위치, 값) - 위치 앞에 넣기

    // 3. 제거: pop_front(), pop_back(), erase() - 임의 위치
    
    // 4. 접근
    int n1 = v[0];  // list 안됨
    int n2 = v.at(0);   // list 안됨
    int n3 = v.front(); // 삽입/삭제가 아니므로 vector도 가능
    int n4 = v.back();
    
    // 5. 요소 변경
    std::vector<int> v8 = { 1, 2, 3};
    std::vector<int> v9 = { 1, 2, 3, 4, 5};
    v8.assign(v9.begin(), v9.end());
    v8.clear();
    
    // 6. 기타 함수들
    bool b = v.empty();
    int n = v.size();
    
    

}
