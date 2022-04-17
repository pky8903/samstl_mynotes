//
//  string.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream>
#include <string>

// std::string의 실제 클래스 이름은 "basic_string"입니다.
// 아래 모양 참고
template<typename T, // char 또는 wchar_t 사용
        typename Traits = std::char_traits<T>, // 비교 정책 담은 단위 전략
        typename Alloc = std::allocator<T> > // 메모리할당기
class basic_string
{
    
};

using string = basic_string<char>;      // ansi 문자열
using wstring = basic_string<wchar_t>;  // unicode 용

int main()
{
    std::string s1 = "abcd";
}
