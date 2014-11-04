//
//  Julian.h
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#ifndef __lab2__Julian__
#define __lab2__Julian__

#include <iostream>
#include "Date.h"

class Julian: public Date {
    
private:
//    int _year;
//    int _month;
//    int _day;
//    std::string _week_day_name;
//    std::string _month_name;
    int days_month[12];
    
    void change_date(const int & d);
    
public:
    
    Julian();
    Julian(int y, int m, int d); // Default
    Julian(const Date & d); // Copy constructor
     ~Julian();
//    Date::~Date();
     Date & operator++();
     Date & operator--();
     Date & operator+=(const int & a);
     Date & operator-=(const int & a);
    
     Date & operator=(const Date & d);
     Date & operator=(Date && d);
    
     Date & add_month(int n = 1);
     Date & add_year(int n = 1);
    
    
    bool leap_year(int & y) const;
    
     int mod_julian_day() const;
    
     int week_day() const;
     int days_per_week() const;
     int days_this_month() const;
     int months_per_year() const;
    int days_in_month(int m, int y) const;
    
};

#endif /* defined(__lab2__Julian__) */
