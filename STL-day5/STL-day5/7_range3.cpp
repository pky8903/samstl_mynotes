//
//  7_range3.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <vector>

// 아래 클래스가 하는 일을 잘 생각해볼 것
template<typename R>
class reverse_view
{
    R& range;
public:
    reverse_view(R& r) : range(r) {}
    
    auto begin() { return range.rbegin(); }
    auto end()  { return range.rend(); }
};

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for (auto e : reverse_view(v))
    {
        std::cout << e << std::endl;
    }
    
}
