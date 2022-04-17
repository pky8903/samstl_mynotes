//
//  QA.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <concepts>

// C++이 아닌 대부분의 언어에는 Generic 제약(constraint)라는 개념이 있다.
// C++은 generic 제약 문법이 C++20에서야 도입되었음.

// 1. C++11 ~ C++17 까지는 enable_if라는 기술(문법이 아닌 테크닉)로 해결
// 2. C++20에서는 concept이라는 문법 도입.

/* C++20
template<typename T> requires std::predicate<T, int, int>
void Sort(int*, int*, T cmp)
{
    cmp(0, 1);
}
*/


int main()
{
    int x[8] = { 1, 3, 4, 5, 7, 8, 9, 6};
    int k = 0;
    Sort(x, x+10, k); // ??
    // 일단 template이니, 컴파일러가 Sort(int*, int*, int)생성은 하지만, int는 function이 아니므로 argument를 받을 수 없어 에러가 나온다.
}
