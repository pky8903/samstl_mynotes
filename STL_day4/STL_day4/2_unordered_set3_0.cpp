//
//  2_unordered_set3_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <unordered_set>
#include "show.h"

// 사용자 정의 타입을 unordered(hash)에 넣기
struct People
{
    std::string name;
    int  age;

    People(std::string n, int a) : name(n), age(a) {}
};

// People에 대한 hash functor가 필요하다
struct PeopleHash
{
    std::size_t operator()(const People& p) const
    {
        std::hash<int> hi;
        std::hash<std::string> hs;
        return hs(p.name) + hi(p.age);
    }
};

// People 객체 2개를 비교할 수 있는 functor
struct PeopleEqual
{
    inline bool operator()(const People& p1, const People& p2){
        return p1.name == p2.name && p1.age == p2.age;
    }
};

int main()
{
    std::unordered_set<People, PeopleHash, PeopleEqual> s;

    s.emplace("kim", 20); // s.insert( People("kim",20))
    s.emplace("lee", 25);
    s.emplace("park", 30);

    People peo("lee", 25);
    auto p = s.find( peo );

    std::cout << (*p).name << std::endl;
}

