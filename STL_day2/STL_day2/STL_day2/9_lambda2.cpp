//
//  9_lambda2.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <vector>
#include <algorithm>
#include <functional> // 이 안에 이미 만들어진 다양한 functor가 있다.
                      // less<>, greator<> 등
#include "show.hpp"

// 람다표현식을 보고 컴파일러가 만드는 클래스
// 클래스이름 자체는 컴파일러가 임의로 결정.
class ClosureType
{
public:
    inline auto operator()(int a, int b) const
    {
        return a + b;
    }
};

int main()
{
    // 람다표현식을 표현하면
    // 1. 위와 같은 클래스를 컴파일러가 생성하고
    // 2. 람다표현식 코드를 "생성된 클래스의 임시 객체를 생성"하는 코드로 변경
    // [](int a, int b) { return a + b; }; // 이 부분을
    // ClosureType() // 이렇게 변경
    
    auto f = [](int a, int b) { return a + b; }; // 컴파일러가 만든 클래스 이름을 모르니 auto로 받음.
    auto g = [](int a, int b) { return a + b; }; // 컴파일러가 만든 클래스 이름을 모르니 auto로 받음.
    
    std::cout << typeid(f).name() << std::endl; // 컴파일러가 만든 클래스 이름
    std::cout << typeid(g).name() << std::endl; // 컴파일러가 만든 클래스 이름, 이름이 다르다.
    
    // 따라서
    bool b1 = (f == g); // 이렇게 할 수 없다.
    
    std::cout << f(1, 2) << std::endl;
    std::cout << f.operator()(1, 2) << std::endl;
};
