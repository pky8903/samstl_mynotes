//
//  2_unordered_map2_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "show.h"

int main()
{
//    std::map<std::string, std::list<int> > indexMap;

    std::unordered_map<std::string, std::list<int> > indexMap;
    // map과 달리 정렬을 유지하지 못한다.
    
    std::ifstream f("/Users/kyoungyoonpark/Documents/Projects/Algorithm/STL_Programming/STL/STL_day4/STL_day4/1_map2.cpp");
    
    int no = 0;  // line number 관리
    
    std::string s;
    
    while (std::getline(f, s))      // 파일로부터 한 줄 읽기
    {
        ++no;
        std::istringstream iss(s);  // 한 줄의 문장을
        std::string word;
        
        while (iss >> word)         // 단어별로 분리
        {
            // map["key"] " 키가 있으면 value 반환, 없으면 키 생성
            indexMap[word].push_back(no);
        }
    }
    
    //----------------------------------------------
    for (auto& p : indexMap)
    {
        std::cout << p.first << " : "; // 단어 출력
        show(p.second); // p.second는 std::list<int>
    }
}


