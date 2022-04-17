//
//  5_functor3.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <bitset> // STL이 제공하는 "비트"를 관리하는 클래스

template<int COUNT, int BASE = 0>
class URandom
{
private:
    std::bitset<COUNT> bs;
    bool recycle;
    
public:
    URandom(bool b = false): recycle(b)
    {
        bs.set(); // 모든 비트를 1로
    }
    
    int operator()()
    {
        if (bs.none())
        {
            if (recycle == true)
                bs.set();
            else
                return -1;
        }
        
        int v = -1;
        while ( !bs.test(v = rand()%COUNT ));
        
        bs.reset(v);
        
        return v + BASE;
    }
    
    void reset() { bs.set(); } // 모두 1로
    int count() { return bs.count(); } // 남아있는 난수의 갯수
};

URandom<100, 100> urand(true);

int main()
{
    std::cout << urand.count() << std::endl;
    for (int i = 0; i < 15; ++i){
        std::cout << urand() << ", ";
    }
    std::cout << std::endl;
    std::cout << urand.count() << std::endl;
}
