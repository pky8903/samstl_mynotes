#include "show.h"
#include <set>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	std::set<Point> s;

	s.insert(Point(5, 5)); 
	s.emplace(3, 2);
	s.emplace(2, 1);
	s.emplace(1, 5);

	// �Ʒ� 2���� �� ������ ������ - �߿��մϴ�.!
	// equality, Equivalency

	auto ret1 = s.find(Point(3, 2));
	auto ret2 = std::find(s.begin(), s.end(), Point(3, 2));
}










