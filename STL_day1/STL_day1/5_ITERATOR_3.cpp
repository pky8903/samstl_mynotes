//
//  5_ITERATOR_3.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> s = { 1,2,3,4,5 };
    
    // 반복자를 꺼내는 법
    // 1. C++ 이전 스타일
    std::list<int>::iterator p = s.begin(); // it should be modified when we change a container (e.g. vector)
    
    // 2. C++ 이후라면 auto 사용합니다.
    std::vector<int> s2 = {1, 2, 3, 4, 5};
    //auto p2 = s2.begin(); // this code causes error when e is a ray array.
    
    // 3. C++11 이후, 유연성이 가장 좋은 코드는
    auto p2 = std::begin(s);     // s가 STL 컨테이너 뿐 아니라 raw array라도 okay.
    
    // 4. C++ 20 이후,
    //auto p2 = std::ranges::begin(s); // <ranges> hearder is required
                                    // more safer than the method 3
                                    // c++20.
}



