//
//  8_bind5.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std::placeholders;

class Machine
{
public:
    void mf1(int a)        { std::cout << "mf1" << std::endl; }
    void mf2(int a, int b) { std::cout << "mf2" << std::endl; }
};

void f0()                    { std::cout << "f0" << std::endl; }
void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}


class Button
{
    using HANDLER = std::function<void()>;
    std::vector<HANDLER> v;
    
public:
    Button(HANDLER h = 0)
    {
        if (h != 0)
            v.push_back(h);
    }
    
    void addHandler(HANDLER h) { v.push_back(h); }
    
    void click()
    {
        for (auto f : v)
            f(); // f는 결국 function이므로 ()로 호출하면 됩니다.
    }
};

int main()
{
    Button b1(&f0);
    Button b2(std::bind(&f1, 2));
    Button b3(std::bind(&f1, 3));
    
    b1.addHandler([](){std::cout << "lambda" << std::endl; });
    b1.addHandler(std::bind(&Machine::mf1, Machine(), 10));
    
    b1.click();
    
    b2.click();
    
    b3.click();
    
    // callback 함수 등록하고 (주로 람다)
    // event handling하는 위 코딩 기법이 많이 쓰인다. (요즘)
}
