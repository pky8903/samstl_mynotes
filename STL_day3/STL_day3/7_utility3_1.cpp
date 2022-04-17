//
//  7_utility3_1.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 파일 스트림
#include <sstream>  // 메모리(스트링) 스트림
#include <string>
#include <iomanip>

// C++ 내부에 아래 코드가 있습니다.
// std::ostream cout;

int main()
{
    //std::ostringstream sout;
    
    int n = 3;
    double d = 3.4574532545232366;
    
    // n, d의 값을 서식화된 문자열로 만들고 싶다.
    // ex) "n = 3, d = 3.4"의 문자열로
    
    // 1. C 스타일
    char s[32];
    // sprintf(s, "n = %d, d = %lf", n, d); // n, d의 값에 따라 버퍼 오버 플로우 가능성 있음.
    snprintf(s, 32, "n = %d, d = %lf", n, d); // 버퍼가 작으면 문자열 잘림
    
    // 1. C++ 스타일
    std::ostringstream sout;
    
    sout << "n = " << n << ", ";
    sout << "d = " << std::setprecision(20) << d; // 소수점 이하 자리수 지정
    
    std::string s1 = sout.str();
    std::cout << s1 << std::endl;
    
}
