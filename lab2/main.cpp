//
//  main.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include <iostream>
#include "Julian.h"
#include "Gregorian.h"
using namespace lab2;
using namespace std;

int main(int argc, const char * argv[])
{

    Gregorian g(1900, 1, 13);
    Julian j(1900, 1, 1);
//    j.add_month(48);
//    j.add_year(4);
//    --j;
//    j.add_year(1);
//    j.add_year(-1);
//    Julian j2(1860, 2, 28);
//    std::cout << (j != j2) << std::endl;
    std::cout << j << " " << j.mod_julian_day() << std::endl;
    cout << g << " " << g.mod_julian_day() << endl;
    cout << (j == g) << endl;
    
//    int foo = j.mod_julian_day();
//    std::cout << foo << std::endl;
//    Julian j2(1864,2,29);
//    int bar = j2.mod_julian_day();
//    std::cout << bar << std::endl;
    return 0;
}

