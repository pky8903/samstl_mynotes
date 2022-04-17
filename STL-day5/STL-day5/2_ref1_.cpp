//
//  2_ref1_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

#include <iostream>
#include <functional>

int main()
{
    int n1 = 10;
    int n2 = 20;

//    for C++ reference
//    int& r1 = n1;
//    int& r2 = n2;

//    for C++ reference
//    r1 = r2;    // 이 순간의 동작 방식을 생각해보기 (r2의 값이 r1으로 넘어온다)
                // r1 --> n1 [    ]
                // r2 --> n2 [    ]
                // r1은 계속 n1만 가리킨다
                // r1 = r2에서 r2가 가리키는 값이 r1이 가리키는 메모리로 이동한다.
                // C++ reference: 이동 불가능한 참조, = 연산시 "참조의 이동이 아니라 값의 이동"
 
    
    std::reference_wrapper<int> r1(n1);     // 이동 가능한 참조
    std::reference_wrapper<int> r2(n2);
    
    r1 = r2;    // 이 순간의 동작 방식을 생각해보기
                // r1 --> n2[]
                // r2 --> n2[]가 된다.
                // 따라서 n1은 변화가 없음
    

    // 결과 예측해보세요                    // int&     reference_wrapper
    std::cout << n1 << std::endl;      // 20        10
    std::cout << n2 << std::endl;      // 20        20
    std::cout << r1 << std::endl;      // 20        20
    std::cout << r2 << std::endl;      // 20        20
}
