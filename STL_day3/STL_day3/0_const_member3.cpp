#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
    
    bool operator==(const Point& pt) const // 뒤에 const를 붙인다.
    {
        return x == pt.x && y == pt.y;
    }
};
int main()
{
	Point p1(1, 2);
	Point p2(1, 2);

	if (p1 == p2)
	{
        std::cout << "same points" << std::endl;
	}
}


