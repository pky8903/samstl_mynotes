//
//  5_unique_ptr2_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <memory>
#include <iostream>

int main()
{
    // std::shared_ptr: 자원의 공유가 가능한 스마트 포인터
    // std::unique_ptr: 자원의 독점.
    
    std::unique_ptr<int> up1(new int);
//    std::unique_ptr<int> up2 = up1; // error
    
    std::cout << sizeof(up1) << std::endl;
    std::cout << sizeof(int*)   << std::endl;
}
