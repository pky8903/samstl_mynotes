//
//  7_range2.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <vector>

// 아래 클래스가 하는 일을 잘 생각해볼 것
template<typename R>
class take_view
{
    R& range;
    std::size_t count;
public:
    take_view(R& r, std::size_t sz) : range(r), count(sz) {}
    
    auto begin() { return range.begin(); }
    auto end()  { return range.begin() + count; }
};

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // tv는 v와 3을 보관하고 있습니다.
    take_view< std::vector<int> > tv(v, 3);
    
//    for (auto e : v){
//    for (auto e : tv){  // begin과 end가 필요하다 (range 소스 참고)
    for (auto e : take_view(v, 3))
    {
        std::cout << e << std::endl;
    }
    
}

// 참고사이트
// 1. godbolt.org ==> C++(뿐 아니라 거의 모든 언어)를 어셈블리로 확인 가능
// 2. cppinsights.io ==> 다양한 C++ 문법의 원리를 보여주는 사이트ㄹ
