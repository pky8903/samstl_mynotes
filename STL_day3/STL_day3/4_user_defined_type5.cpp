//
//  4_user_defined_type5.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <vector>
#include <iostream>

class Point
{
    
};

class Rect
{
    
};

int main()
{
    // 1.
    std::vector<Point> v1;      // Point 밖에 저장할 수 없음
    
    // 2. void* 보관
    // 단점 1. 정말 모든 타입 주소 가능. 연관성 없는 것들도. 이 특징이 오히려 버그의 원인
    // 단점 2. 꺼냈을 때 나오는 주소가 어느 타입인지 알 수 없다.
    std::vector<void*> v2;      // 모든 타입 주소 저장 가능
    v2.push_back(new Point);
    v2.push_back(new Rect);
    v2.push_back(new int);
    void* p = v[0];
    
    // 방법3. 기반 클래스를 만든 후, 기반 클래스 포인터 보관(upcasting): 4_user_defined_type6
}
