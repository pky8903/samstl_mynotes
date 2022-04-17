//
//  5_string_view2_.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// 5_string_view
#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t sz)
{
    std::cout << sz << "메모리 할당됨" << std::endl;
    return malloc(sz);
}

// 인자로 문자열을 받고 싶습니다.
// 1. 가장 나쁜 코드
//void foo(std::string name)
//{
//    // 읽기만 할거면 복사본이 필요 없다.
//}

// 2. 가장 좋은 코드
void foo (std::string_view name)
{

}

// 3. 아래 코드를 하면 되지 않나요?
//void foo (const std::string& name) {}
// 아래 foo("dlfkajslfkdsaf")를 call 할 때, 임시객체생성/동적메모리할당 후 문자열을 heap에 보관
// 이를 가리키는 포인터를 만들어서 참조를 하게 됨.

// 반면 2에서는
// 상수 메모리에 이미 할당된 "aldfkjdsalfdjsaf"을
// string_view로 가리키기만 해서 보게 되므로 동적메모리할당이 추가적으로 일어나지 않음.

int main()
{
//    std::string s = "sdjfsljflsjlsdkjfssfsd";
//    foo(s);
    foo("dlfasjfkdslfjaksf");
}





