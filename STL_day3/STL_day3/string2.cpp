//
//  string2.cpp
//  STL_day3
//
//  Created by Kyoungyoon Park on 2022/04/13.
//

#include <iostream>
#include <string>
#include "debug_alloc.hpp"

using debug_string = std::basic_string<char,
                        std::char_traits<char>, debug_alloc<char>>;
int main()
{
    debug_string s1 = "012345678912345";
}

