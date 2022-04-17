//
//  main.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

// 1_STL_PREVIEW1
#include <iostream>
#include <string>

int main()
{
    char s1[] = "Hello";
    char s2[] = "Hello";

    if (s1 == s2) {} // always false
                    // strcmp(s2, s3) == 0
    
    std::string s3 = "hello";
    std::string s4 = s3;
    s4 = s3;
    s4 = s3 + s3;
    
    if (s3 == s4) { std::cout << s4; }
    
    std::cout << s4;
    
    std::string s = "abcd"; // 1) dynamic allocation and heap?
                            // 2) static allocation and pointer?
                            // answer is 2. 1 is for longer strings.
    
    //s2 = s1;
}
