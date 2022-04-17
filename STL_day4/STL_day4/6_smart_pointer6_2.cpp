//
//  6_smart_pointer6_2.cpp
//  STL_day4
//
//  Created by Kyoungyoon Park on 2022/04/14.
//

#include <memory>
#include <cstdlib>

int main()
{
//    FILE* f = fopen("a.txt", "wt");
//    fclose(f);

    std::shared_ptr< FILE > pf( fopen("a.txt", "wt"), fclose );

    fprintf(pf.get(), "hello");

}
