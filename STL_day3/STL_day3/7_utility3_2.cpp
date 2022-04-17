//
//  7_utility3_2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 파일 스트림
#include <sstream>  // 메모리(스트링) 스트림
#include <string>
#include <iomanip>

//                출력                         입력
// 표준스트림        std::ostream cout           std::istream cin
// 파일스트림        std::ofstream               std::ifstream
// 메모리(문장열)     std::ostringstream          std::istringstream

int main()
{
    std::istringstream iss("to be or not to be");
    
    std::string s;
    
    // std::cin >> s; // 표준 입력 (사용자)로부터 한 단어 읽기
    
    // iss >> s;   // "to" 만 꺼냄
    // std::cout  << s << std::endl;
    
    while (iss >> s)
        std::cout << s << std::endl;
}
