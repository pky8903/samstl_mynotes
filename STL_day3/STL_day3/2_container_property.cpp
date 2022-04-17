std::list<int> s = { 1,2,3 };

// 1. 멤버 타입이 있다.
std::list<int>::value_type n = s.front();
std::list<int>::size_type    = s.size();

class AAA
{
private:
    int data;   // member data
    
public:
    void foo() {} // member function
    
    using iterator = slist_iterator;    // member type
    using value_type = int;             // member type
}

// 2. 반환과 제거를 동시에 하지 않는다. => 그래서 멀티스레드 환경에서 사용시 꼭 동기화가 필요하다.
int n = s.back();    // 반환만. 제거되지 않는다.
s.pop_back();        // 제거만 한다. 반환 타입은 void

// 3. 단위 전략을 많이 사용한다.
std::list<int, MyAlloc<int>> s2;
std::set<int, greater<int>, MyAlloc<int>> ss;
