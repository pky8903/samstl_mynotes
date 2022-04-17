#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.hpp"

class FindChar
{
    std::string data;
public:
    FindChar(const std::string& s): data(s) {}
    
    inline bool operator() (char c) const
    {
        return std::find(data.begin(), data.end(), c) != data.end();
    }
};

int main()
{
    std::vector<std::string> v;
    std::ifstream f("/Users/kyoungyoonpark/Documents/Projects/Algorithm/STL_Programming/STL/STL_day3/STL_day3/3_sequence_container6.cpp"); // current file name

    std::string s;
    
    // f >> s           : 파일에서 한 단어 읽기
    // getline(f, s)    : 파일에서 한 문장     getline(std::cin, s)도 된다.

    // 줄단위로 읽어서 각 줄을 벡터 엘리먼트로 보관.
    while (std::getline(f, s))
        v.push_back(s);
    //----------------------------

//    std::reverse(v.begin(), v.end());
//    std::reverse(v[0].begin(), v[0].end()); // 첫번째 줄을 좌우로 뒤집기
    
    for (auto& e : v)
    {
//        std::reverse(e.begin(), e.end());
//        std::replace(e.begin(), e.end(), 'i', ' ');
        // 모든 모음을 공백 처리
//        std::replace_if(e.begin(), e.end(),
//                        [](char c){ return c == 'a' || c == 'e';},
//                        ' ');
        FindChar fc("0123456789");  // 람다가 좋으나, functor는 재사용성이 좋다.
        std::replace_if(e.begin(), e.end(), fc, ' ');
    }

    //-------------------------------------
    for (auto& n : v)
        std::cout << n << std::endl;
}
