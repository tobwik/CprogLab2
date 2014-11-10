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
   std::cout << "----------------------------------------" << std::endl;
	Calendar<Gregorian> cal;
	cal.set_date(2000, 12, 2);
	cal.add_event("Basketträning", 4, 12, 2000);
	cal.add_event("Basketträning", 11, 12, 2000);
	cal.add_event("Nyårsfrukost", 1, 1, 2001);
	cal.add_event("Första advent", 1); // år = 2000, månad = 12
	cal.add_event("Vårdagjämning", 20, 3); // år = 2000
	cal.add_event("Julafton", 24, 12);
	cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
	cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
	// ignoreras och inte sättas in i kalendern
	cal.add_event("Min första cykel", 20, 12, 2000);
	cal.remove_event("Basketträning", 4);
	std::cout << cal; // OBS! Vårdagjämning och första advent är
	// före nuvarande datum och skrivs inte ut
	std::cout << "----------------------------------------" << std::endl;
	cal.remove_event("Vårdagjämning", 20, 3, 2000);
	cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000);
	std::cout << cal.cDate << endl;
	cal.set_date(2000, 11, 2);
	std::cout << cal.cDate << endl;
	if (! cal.remove_event("Julafton", 24)) {
	std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
	<< " bort något eftersom aktuell månad är november" << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << cal.cDate << endl;
	std::cout << cal;

//    int foo = j.mod_julian_day();
//    std::cout << foo << std::endl;
//    Julian j2(1864,2,29);
//    int bar = j2.mod_julian_day();
//    std::cout << bar << std::endl;
   return 0;
}

