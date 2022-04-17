//
//  6_unique_ptr5_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <memory>
#include <iostream>

int main()
{
    std::unique_ptr<int> up(new int);
    std::shared_ptr<int> sp(new int);

    // 다음 중 에러는?
    std::shared_ptr<int> sp1 = up;              // error
    std::shared_ptr<int> sp2 = std::move(up);   // okay

    std::unique_ptr<int> up1 = sp;              // error
    std::unique_ptr<int> up2 = std::move(sp);   // error
}

// 아래 Alloc에서 반환값을 int* 대신 smart pointer로 shared_ptr로 할까요? Unique_ptr로 할까요?
//int* Alloc()
// std::shared_ptr<int> Alloc()    // 호출자는 반드시 shared_ptr로만 받아야 한다. (unique_ptr은 shared_ptr을 받을 수 없다)
std::unique_ptr<int> Alloc()        // 호출자는 shared_ptr 또는 unique_ptr을 선택 가능
{
//    return new int;
    return std::unique_ptr<int>(new int);
}

int main()
{
    std::shared_ptr<int> sp1 = Alloc();     // 임시객체가 들어갈 때 std::move로 들어가기 때문에 error가 아님.
    std::unique_ptr<int> up1 = Alloc();     // 임시객채가 들어갈 때 std::move로 들어가기 때문에 error가 아님.
}
