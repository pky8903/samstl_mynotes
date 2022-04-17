//
//  string3.cpp
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
    
};

int main()
{
    std::string s1 = "abcd";
    std::string s2 = "ABCD";
    
    
}
