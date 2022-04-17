#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}
    
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
};
int main()
{
	// Point pt(1, 2);
    
    const Point pt(1, 2);   // 핵심: 상수 객체일 때 print를 호출하기 위해 print 선언부에 const를 붙인다!!

	// pt.x = 10;       // error. even though x is in public, pt is const.
    // pt.set(10, 20);  // error. pt is const.
	// pt.print();      // error!! 만약에 선언부와 구현부를 나눠 구현했다고 해보자. 컴파일러가 선언부만 보고 해당 함수가 멤버 변수를 바꾸는지 안바꾸는지 알 수 없다.
                        // 만약 바꾸고 싶다면? const function이 필요하다.
                        // 핵심: 상수 객체는 상수 멤버 함수만 호출할 수 있다.
    pt.print();         // okay. 단, print()가 상수 멤버 함수라면.
}


