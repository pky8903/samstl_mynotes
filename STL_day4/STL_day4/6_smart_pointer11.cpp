//
//  6_smart_pointer11.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <memory>

class Car
{
public:
    void Go() {}
    ~Car() {std::cout << "~Car" << std::endl;    }
};
int main()
{
    std::weak_ptr<Car>   wp;
    {
        std::shared_ptr<Car> p(new Car);
    } // <== p가 파괴되므로 객체 파괴
    
    if (!wp.expired()) // 결국 아래 if(sp)로 조사하므로 없어도 된다.
    {
        std::shared_ptr<Car> sp = wp.lock();
        
        if (sp)
        {
            sp->Go();
        }
        else
        {
            std::cout << " sp 유효하지 않음 " << std::endl;
        }
    }
}

