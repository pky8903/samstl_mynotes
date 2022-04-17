//
//  5_array2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <algorithm>
#include "show.hpp"

// 아래 코드를 잘 생각해볼 것
template<typename T, std::size_t N>
class array
{
public:
    int buff[N];
    
    inline int size() const { return N; }
    inline bool empty() const { return N != 0; }
    
    using value_type = T;
    using iterator = T*;
    using reference = T&;
    
    iterator begin()    { return buff[0]; }
    iterator end()      { return buff + N; }
};

int main()
{
    // array
    // 1. 모든 요소가 스택에 있습니다 (배열과 동일)
    array<int, 10> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 2. raw array는 멤버 함수가 없지만, array는 멤버함수가 있습니다.
    std::cout << arr.size() << std::endl;
    
    // 3. 다른 컨테이너처럼 ㅏ용 가능
    auto p = arr.begin();

    // 4. begin(), end()가 있는 모든 타입은 range_for도 됩니다.
    for (auto e : arr)
    {
        std::cout << e << std::endl;
    }
}
