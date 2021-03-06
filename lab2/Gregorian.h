//
//  Gregorian.h
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#ifndef __lab2__Gregorian__
#define __lab2__Gregorian__

#include <iostream>
#include "Date.h"
#include <stdexcept>

//using namespace lab2;

namespace lab2 {
    
    class Gregorian: public Date {
        
    private:
        //    int _year;
        //    int _month;
        //    int _day;
        //    std::string _week_day_name;
        //    std::string _month_name;
        int g_days_month[12];
        
        void change_date(const int & d);
        void init();
        bool leap_year(int & y) const;
        
    public:
        
        Gregorian();
        Gregorian(int y, int m, int d); // Default
        Gregorian(const Date & d); // Copy constructor
        Gregorian(const Gregorian & g);
        ~Gregorian();
        //    Date::~Date();
        Date & operator++();
        Date & operator--();
        Gregorian operator++(int i);
        Gregorian operator--(int i);
        
        Date & operator+=(const int & a);
        Date & operator-=(const int & a);
        
        Date & operator=(const Date & d);
        Date & operator=(const Gregorian & g);
        Date & operator=(Date && d);
        
        Date & add_month(int n = 1);
        Date & add_year(int n = 1);
        
        
        
        int mod_julian_day() const;
        
        int week_day() const;
        int days_per_week() const;
        int days_this_month() const;
        int months_per_year() const;
        int days_in_month(int m, int y) const;
        
        std::string week_day_name() const;
        std::string month_name() const;
        
    };
}

#endif /* defined(__lab2__Gregorian__) */
