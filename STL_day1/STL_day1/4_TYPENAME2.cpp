//
//  4_TYPENAME2.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>
#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& v)
{
    int n = v.front();
    std::cout << n << std::endl;
}
 */

/*
template <typename T>
void print_first_element(std::vector<T>& v)
{
    T n = v.front();
    std::cout << n << std::endl;
}
*/

// std::vector 말고 std::list 이렇게 임의의 container도 자유롭게 받고 싶으면?
template <typename T>
void print_first_element(T& v)
{
    typename T::value_type n = v.front(); // 컨테이너가 저장하는 type을 외부에서 어떻게 알 것인가?
                                        // 템플릿 클래스에서 type을 가져오려면 typename을 붙여야함! 아니면 컴파일러가 value로 인식함.
                                        // C++11 이후로는 auto로 해결할 수 있지만, value_type은 여전히 중요함.
    std::cout << n << std::endl;
}

/*
// 그래서 규칙이 있다.
template<typename T>
class list
{
public:
    using value_type = T; // STL의 모든 컨테이너에는 이 코드가 있음.
    // ...
};
*/

int main()
{
    std::list<double> v = { 1,2,3,4,5,6,7,8,9,10 };

    print_first_element(v);
}
