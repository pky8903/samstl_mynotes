//
//  2_ref2_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <functional>

// 이동 가능한 참조를 만들어봅시다.
// reference_wrapper: 얕은 복사를 하는 포인터
template<typename T> struct reference_wrapper
{
    T* ptr;
public:
    reference_wrapper(T& obj): ptr(&obj) {}
    
    operator T&(){ return *ptr; }
};

// C++ reference: 깊은 복사를 하는 포인터

int main()
{
    int n1 = 10;
    int n2 = 20;
    
    reference_wrapper<int> r1(n1);     // 이동 가능한 참조
    reference_wrapper<int> r2(n2);
    
    r1 = r2;        // r1 f2 모두 reference_wrapper 타입이므로
                    // reference_wrapper의 대입연산자 호출
                    // 컴파일러가 생성하는 대입연산자 사용
    
    int& r3 = r1;   // r1.operator int&() 변환연산자 필요
    
    // 결과 예측해보세요                    // int&     reference_wrapper
    std::cout << n1 << std::endl;      // 20        10
    std::cout << n2 << std::endl;      // 20        20
    std::cout << r1 << std::endl;      // 20        20
    std::cout << r2 << std::endl;      // 20        20
}
