//
//  explicit3.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <memory>

void push_back(std::shared_ptr<int> sp)
{
    
}

int main()
{
    // 1. shared_ptr 생성자는 explicit입니다.
    std::shared_ptr<int> sp1 = new int; // error. shared_ptr의 생성자가 explicit이기 때문.
    std::shared_ptr<int> sp2(new int);  // okay
    
    // 2.
    push_back(new int); // std::shared_ptr<int> sp = new int의 의미. 이게 허용되지 않기 때문에 error!
    push_back(std::shared_ptr<int>(new int));
                        // std::shared_ptr<int> sp = std::shared_ptr<int>(new int);
                        // okay. 위 코드는 복사생성자 사용. explicit 아니.
    push_back(std::make_shared<int>(0));
                        // std::shared_ptr<int> sp = std::make_shared<int>(0)
}
