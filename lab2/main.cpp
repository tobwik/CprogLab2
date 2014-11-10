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
#include "Calendar.h"
using namespace lab2;
using namespace std;

int main(int argc, const char * argv[])
{

   // Gregorian g(1900, 1, 1);
   // Julian j(1900, 1, 1);
//    j.add_month(48);
//    j.add_year(4);
//    --j;
//    j.add_year(1);
//    j.add_year(-1);
//    Julian j2(1860, 2, 28);
//    std::cout << (j != j2) << std::endl;
   // std::cout << j << " " << j.mod_julian_day() << std::endl;
   // cout << g << " " << g.mod_julian_day() << endl;
   // cout << (j == g) << endl;
   Calendar<Gregorian> c;
   std::string basket("Basket");
   c.add_event(basket, 1, 3, 2000);
   c.add_event("Basket",1, 3, 2000);
   c.add_event("asdfqwer",3);

   Calendar<Julian> j(c);
   // j = c;
   cout << j << endl;
//    int foo = j.mod_julian_day();
//    std::cout << foo << std::endl;
//    Julian j2(1864,2,29);
//    int bar = j2.mod_julian_day();
//    std::cout << bar << std::endl;
   return 0;
}

