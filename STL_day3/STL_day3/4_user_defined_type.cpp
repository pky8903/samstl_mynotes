//
//  4_user_defined_type.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include "show.hpp"

class Point
{
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
};
int main()
{
    // 1. 아래 코드는 Point의 default construtor가 10번 호출되는 코드입니다.
    // 2. Point default constructor가 없으면 error입니다.
    std::vector<Point> v(10);
    
    // default constructor가 없는 타입을 vector에 넣을 때는
    // 1. 10개 만들때 복사 초기화 하기 위한 객체를 전달
    Point pt(0, 0);
    std::vector<Point> v1(10, pt);
    std::vector<Point> v2(10, Point(0, 0));
    std::vector<Point> v3(10, { 0, 0 });    // C++11부터는 이 코드도 가능
    
    // 2. 모든 요소에 초기값을 다르게 하려면
    std::vector<Point> v4 = { Point(0, 0), Point(1, 1), Point(2, 2)};
    std::vector<Point> v5 = { {0, 0}, {1, 1}, {2, 2}};  // C++11 부터 가능
    std::vector<Point> v6 { {0, 0}, {1, 1}, {2, 2}};    // C++11 부터 가능
    
    // 3. resize의 경우도 default constructor가 없으면 주의해야한다.
    std::vector<Point> v7(10, {0, 0});
//    v7.resize(15);      // 늘어난 5개에 대해서는 생성자 호출이 필요한데
                        // default constructor가 없으므로 에러
    
    v7.resize(15, {0, 0});  // okay.
//    v7.resize(7);           // 될것같은데 안됨
    v7.resize(7, {0, 0});
    
    // ----------------------------------------------
    // 아래의 코드를 생각해보기
    std::vector< std::vector<int> > m1(10);
//    std::vector< std::vector<int> > m2(10, 10); // error
    std::vector< std::vector<int> > m3(10, {10});
    std::vector< std::vector<int> > m4(10, std::vector<int>(10));
    std::vector< std::vector<int> > m5(10, std::vector<int>(10, 3));
    
//    m1[2][2] = 10;  // runtime error. m1은 10개지만, m1[2]의 vector 크기는 0.
    std::cout << m3[0][0] << std::endl; // 10
    std::cout << m5[0][0] << std::endl; // 3
    
    // 정리
    // 1. 복사 생성자가 없는 타입은 컨테이너에 넣을 수 없음.
    // 2. 디폴트 생성자가 없는 타입은 꼭 위처럼 복사할 객체를 전달해야한다.
}

