//
//  5_string_view_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// 5_string_view
#include <iostream>
#include <string>
#include <string_view> // C++17에서 추가

int main()
{
    std::string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // 긴 것은 별도의 메모리로 소유
    
    // "s2"와 "sv"의 메모리 그림을 잘 알아둘것
    std::string s2 = s1;    // s1의 문자열을 깊은 복사해서
                            // s2가 별도의 메모리로 소유
    
    std::string_view sv = s1;
                            // sv는 문자열을 소유하지 않고
                            // s1의 문자열을 공유
                            // 단, sv로는 읽기만 가능
    
    auto ret = sv[0];       // okay.
    sv[0] = 'A';            // error
}
