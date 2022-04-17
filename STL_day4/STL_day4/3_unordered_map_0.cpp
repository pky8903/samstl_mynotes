//
//  3_unordered_map_0.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    // pair를 저장하는 hash (unordered_set)
    std::unordered_map<std::string, std::string> m;
    
    // map과 사용법이 거의 동일합니다
    m["sun"] = "일요일";
    
    auto ret = m.find("sun");
    

}



