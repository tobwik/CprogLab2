//
//  main.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include <iostream>
#include "Julian.h"

int main(int argc, const char * argv[])
{

    Julian j(1858, 11, 17);
//    j.add_month(1);
    //j.add_year(4);
    int foo = j.mod_julian_day();
    std::cout << foo << std::endl;
    return 0;
}

