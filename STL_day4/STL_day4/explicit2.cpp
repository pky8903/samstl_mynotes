//
//  explicit2.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <string>
#include <vector>

void f1(std::string s)      {}
void f2(std::vector<int> v) {}

int main()
{
    std::string s1("A");    // okay
    std::string s2 = "A";   // okay. explicit 아님.
    std::vector<int> v1(10);    // okay
    std::vector<int> v2 = 10;   // error
    
    // 아래 2줄을 생각해보세요. 되는게 좋을까요? 안되는게 좋을까요?
    f1("A");    // okay. std::string s = "A" 복사 초기화 허용. 즉 explicit 생성자가 아님.
    f2(10);     // error. std::vector<int> v = 10 이 안됨.
                // 즉, explicit 생성자
}
