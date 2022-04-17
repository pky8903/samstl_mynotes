//
//  6_unique_ptr_4.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <memory>
#include <iostream>

int main()
{
    std::unique_ptr<int> up1(new int);
    
//    std::unique_ptr<int> up2 = up1; // error

    std::unique_ptr<int> up2 = std::move(up1);  // ok. 자원의 복사가 아닌 자원의 이동 up1은 더이상 데이터를 가리키지 않음. nullptr.
}
