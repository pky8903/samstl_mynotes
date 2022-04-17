//
//  Container_wrap_up.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

// 컨테이너 정리

// sequence container
// => vector, list, deque,      C++98
// => array, forward_list       C++11
// => string을 이 분류에 넣기도 한다.

// container adapter 3개 (sequence의 함수 이름을 변경하는 도구)
// => stack, queue, priority_queue

// associative container
// => set, map      : tree 기반, 정렬이 필요한데 검색도 빨라야 한다.
// => unordered_set, unordered_map  :   hash 기반, 정렬이 필요없고 검색이 제일 중요하다.

// -----------------------------------
// graph 등이 아직 없습니다.
// boost.org에서 boost library를 설치하면 더 많은 컨테이너를 사용 가능.
// boost 라이브러리에서 안정성과 필요성이 검증되면 추후 C++ 표준에 추가되게 됩니다.

unordered_map<std::string, int> macro;

#define MAX 10

int main()
{
    int n = MAX;

}

// 전처리기 만들어보기 ==> 정렬 필요없고 검색이 제일 중요하므로 hash로 하면 된다.

int

