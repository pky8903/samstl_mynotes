//
//  4_user_defined_type6.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>

class Shape
{
public:
    // "모든 기반 클래스의 소멸자는 반드시 가상함수이어야 한다"라는 규칙이 있으므로
    // 결국 상속을 사용하는 코드는 대부분 가상함수가 한 개 이상은 있다.
    virtual ~Shape() {}
};

class Point : public Shape
{
    
};

class Rect : public Shape
{
public:
    void draw() const {}
};

int main()
{
    // 방법3. 기반 클래스를 만든 후, 기반 클래스 포인터 보관(upcasting)
    std::vector<Shape*> v;
    v.push_back(new Point);
    v.push_back(new Rect);
    v.push_back(new Rect);
    
    // 그런데 v는 Shape*로 보관하고 있으므로 Rect의 소유 멤버 접근은 안됩니다.
//    v[2]->draw(); // error.
    
    // 고유 멤버 접근이 필요하면 캐스팅해야한다.
    // 방법 1. 타입을 명확히 확신할 수 있다면 static_cast.
    Rect* p1 = static_cast<Rect*>(v[0]); // "static" 컴파일할 때 그냥 type fix.
    
    // 방법 2. 확신할 수 없다면 dynamic_cast
    Rect* p2 = dynamic_cast<Rect*>(v[2]); // 얘가 가리키는게 Rect* 인지, "실행할 때" 조사한다. 그래서 dynamic. Rect*면 주소를 주고, 아니면 0을 반환.
                                            // 그런데 어떻게 조사하나?
                                            // 가상함수 테이블이 있어야 조사 가능.
                                            // 실행 시간에 조사하니 느리다.
    
    Rect* p2 = dynamic_cast<Rect*>(v[0]); // 0을 반환.

    
}
