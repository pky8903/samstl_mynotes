//
//  explicit.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>

class Bike
{
    int gear;
public:
    explicit Bike(int n): gear(n) {}
};

void fn(Bike b) {}

int main()
{
    // 인자가 한 개인 생성자가 있으면 아래처럼 4가지 형태로 객체 생성이 가능합니다.
    // C++98
    Bike b1(10);        // direct initialization
//    Bike b2  = 10;      // copy initialization (explicit에 의해 안됨)
    
    // C++11
    Bike b3 {10};       // direct initialization
//    Bike b4 = {10};     // copy initialization (explicit에 의해 안됨)
    
    fn(10);             // ??
                        // Bike b = 10처럼 복사 초기화가 되는 것.
                        // 이렇게 안되는게 좋을 때가 있다. 그럴 땐 생성자에 explicit을 앞에 붙인다.
    
    fn(Bike(10));       // okay. 이 경우는 "Bike b = Bike(10)"이므로
                        // int 인자 한개의 생성자가 아닌
                        // 복사 생성자를 호출하게 됩니다.
}
