#include <map>  
#include "show.h"
// map : pair 를 저장하는 set,   key 값으로 value 를 저장
int main()
{
	std::map<std::string, std::string> m;

	// 요소 넣기
	// 1. pair 만들어서 넣기

	// 2. make_pair

	// 3. emplace

	// 4. [] 연산자 사용
	//------------------------
	
	// 반복자에 대해서
	auto p = m.find("wed"); // find(키값)

	// p를 사용해서 "wed : 수요일" 이라고 출력해보세요

	// [] 연산자
	std::cout << m["sun"] << std::endl; 
}




