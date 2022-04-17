//
//  6_CATEGORY2.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
    std::forward_list<int> s1 = { 1,2,3 };
    std::list<int> s2 = { 1,2,3 };
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

    //auto p = std::find(std::begin(v), std::end(v), 5); // minimal condition: input iterator
    std::reverse(v.begin(), v.end()); // minimal condition: bidirectional iterator
    std::sort(v.begin(), v.end()); // quick sort, random access iterator
    
    // s1: 싱글리스트
    // s2: 더블리스트
    // s3: vector

    std::reverse(s2.begin(), s2.end());
    // std::reverse(s1.begin(), s1.end()); // algorithm fail
    
    // std::sort requires random access iterator
    std::sort(v.begin(), v.end()); // okay.
    //std::sort(s2.begin(), s2.end()); // s2 iterator is bidirectional iterator
    
    // conclusion: STL의 모든 알고리즘은 "자신이 요구하는 반복자의 종류"가 정해져있다. 반드시 조건을 만족하는 반복자를 보내야한다. 에러 메세지를 통해서 반복자 오류를 찾기 힘들다. 따라서 쓸 때 잘 판단해서 써야한다. 반드시 조건을 만족하는 반복자를 보내야한다.
    
    // 그럼 double list는 sort할 수 없을까? quick말고 다른 알고리즘 사용.
    // 그래서 멤버 함수 sort 제공.
    s2.sort(); // quick 말고 다른 알고리즘.
    
    // vector에도 멤버 함수 sort가 있을까?
    // v.sort();? no. random access iterator가 있기 때문에.
}
