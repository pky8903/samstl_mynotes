//
//  string4.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream>
#include <string>

// std::string의 실제 클래스 이름은 "basic_string"입니다.
// 아래 모양 참고
/* template<typename T, // char 또는 wchar_t 사용
        typename Traits = std::char_traits<T>, // 비교 정책 담은 단위 전략
        typename Alloc = std::allocator<T> > // 메모리할당기
class basic_string
{
    T* buff;
    Alloc ax; // ax.allocate
public:
    bool operator==(const basic_string& other)
    {
        // 문자열의 상등 조사도 단위 전략으로 교체할 수 있게 만들었음.
        // 그런데 아래 코드를 잘 보면 compare는 static 멤버 함수로
        // 만들어야함.
        return Traits::compare(buff, other.buff);
    }
    
}; */
//--------------------------------------------
// cppreference.com에 char_traits 검색하면 아래 코드 있습니다.
//--------------------------------------
// cppreference.com ø° char_trais ∞Àªˆ«œ∏È æ∆∑° ƒ⁄µÂ ¿÷Ω¿¥œ¥Ÿ.

/*
struct MyTraits :  public std::char_traits<char>
{
    static bool compare() {}
};
*/
struct MyTraits : public std::char_traits<char> {
    static char to_upper(char ch) {
        return std::toupper((unsigned char)ch);
    }
    static bool eq(char c1, char c2) {
        return to_upper(c1) == to_upper(c2);
    }
    static bool lt(char c1, char c2) {
        return to_upper(c1) < to_upper(c2);
    }
    static int compare(const char* s1, const char* s2, std::size_t n) {
        while (n-- != 0) {
            if (to_upper(*s1) < to_upper(*s2)) return -1;
            if (to_upper(*s1) > to_upper(*s2)) return 1;
            ++s1; ++s2;
        }
        return 0;
    }
    static const char* find(const char* s, std::size_t n, char a) {
        auto const ua(to_upper(a));
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};


using mystring = std::basic_string<char, MyTraits>;

int main()
{
    mystring s1 = "abcd";
    mystring s2 = "ABCD";

    bool b = (s1 == s2);

    std::cout << b << std::endl;


}
