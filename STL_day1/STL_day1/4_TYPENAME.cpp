//
//  4_TYPENAME.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

class Test
{
public:
    enum { value = 1 };
    typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
    Test::value * p;
    Test::DWORD * p;
    
    // "classname::name": "name" is "value" or "type".
    // Test::value *p; // multiplication => value
    // Test:DWORD *p; // pointer var p. => type
    
    //T::value *p; // ok
    //T::DWORD *p; // error
    
    typename T::DWORD *p2;
}
int main()
{
    Test t;
    foo(t);
}
