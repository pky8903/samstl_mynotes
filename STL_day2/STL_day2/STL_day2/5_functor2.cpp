//
//  5_functor2.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <bitset> // STL이 제공하는 "비트"를 관리하는 클래스

// 0부터 9 사이의 중복되지 않은 난수를 반환하는 함수?
// 누군가가 이미 나온 난수를 저장하고 있어야한다. 그러나 함수는 동작이 있는데 상태가 없다. 함수로 구현 불가.--> functor
//int urand()
//{
//    return rand() % 10;
//}

// 일반 함수는 상태를 가질 수 없지만
// functor는 상태를 가질 수 있습니다.  -> 멤버 데이터를 가질 수 있다.

class URandom
{
private:
    std::bitset<10> bs;
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
        while ( !bs.test(v = rand()%10 ));
        
        bs.reset(v);
        
        return v;
    }
};

URandom urand(true);

int main()
{
    for (int i = 0; i < 15; ++i){
        std::cout << urand() << ", ";
    }
}
