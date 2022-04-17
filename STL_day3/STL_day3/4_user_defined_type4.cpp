);//
//  4_user_defined_type4.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <algorithm>
#include "show.hpp"

class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b)
    {
        std::cout << "Point()" << std::endl;
    }
    ~Point() { std::cout << "~Point()" << std::endl; }

    Point(const Point& p)
    {
        std::cout << "Point(const Point&)" << std::endl;
    }
    void dump() const
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    // 두 줄의 차이점은?
    std::vector<Point>  v1(5);
    std::vector<Point*> v2(5);
    v2[0] = new Point(1, 1);
    v2[1] = new Point(1, 1);
    
    
    
    std::vector<Point*> v;

    v.push_back(new Point(1, 2));
    v.push_back(new Point(3, 1));
    v.push_back(new Point(4, 2));
    v.push_back(new Point(2, 2));

    // v를 sort해보면
//    std::sort(v.begin(), v.end());  // 주소도 크기 비교 가능하므로
                                    // 에러는 아니지만
                                    // 논리적으로 말도 안되는 코드
    
    // 결론: 포인터를 저장하는 컨테이너를 마늘고
    // 정렬하려면 아래처럼 "조건자"를 전달하면 됨
    std::sort(v.begin(), v.end(),
              [](const Point* p1, const Point* p2) { return p1->x < p2->x; });


    for (auto p : v)
        p->dump();

    for (auto p : v) delete p;

}
