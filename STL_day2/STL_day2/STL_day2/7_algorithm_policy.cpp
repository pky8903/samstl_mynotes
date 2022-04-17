//
//  7_algorithm_policy.cpp
//  STL_day2
//
//  Created by Kyoungyoon Park on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // accumulate
#include <functional>
#include "show.hpp"

int main()
{
    std::vector<int> v1 = { 1,2,3};

    // 1. sort compare policy
    // std::sort(v1.begin(), v1.end(), [](int a, int b) { return a < b; });
    
    // int n = std::accumulate(v1.begin(), v1.end(), 0);
    
//    int n = std::accumulate(v1.begin(), v1.end(), 1,
//                             [] (int a, int b) { return a*b; });
    
    int n = std::accumulate(v1.begin(), v1.end(), 1, std::multiplies<int>());
    
    std::cout << n << std::endl;

}
