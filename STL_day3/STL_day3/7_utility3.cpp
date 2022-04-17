//
//  7_utility3.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 파일 스트림
#include <sstream>  // 메모리(스트링) 스트림
#include <string>

// C++ 내부에 아래 코드가 있습니다.
// std::ostream cout;

int main()
{
    std::ofstream fout("/Users/kyoungyoonpark/Documents/Projects/Algorithm/STL_Programming/STL/STL_day3/STL_day3/a.txt");
    std::ostringstream sout;    // 메모리(string) 출력 스트림
    
    std::cout << "hello";   // 화면 출력
    fout << "hello";        // 파일 출력
    sout << "hello";        // sout이 내부적으로 가진 문자열에 출력
    
    std::string s = sout.str();     // 결국 s가 가진 "hello" 출력
    std::cout << s << std::endl;

}
