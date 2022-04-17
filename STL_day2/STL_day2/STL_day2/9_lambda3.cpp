//
//  9_lambda3.cpp
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
    // 아래 코드를 보고 sort() 함수는 몇개일지 예측.
    // => 같은 람다 표현식이라도 다른 타입입니다.
    std::sort(x, x+10, [](int a, int b) {return a < b; });
    std::sort(x, x+10, [](int a, int b) {return a < b; });
    std::sort(x, x+10, [](int a, int b) {return a < b; });
    
    // 동일한 람다 표현식을 여러번 사용하려면
    // auto 변수에 담아놓고 사용하는 것이 좋을 때가 있습니다.
};
