//
//  Date.h
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#ifndef __lab2__Date__
#define __lab2__Date__

#include <iostream>


class Date {
    
public:
    //virtual Date() = 0;
    //virtual ~Date() = 0;
    
    Date(int y, int m, int d);
    
    int year() const;
    int month() const;
    int day() const;
    virtual int week_day() const = 0;
    virtual int days_per_week() const = 0;
    virtual int days_this_month() const = 0;
    virtual int months_per_year() const = 0;
    std::string week_day_name() const;
    std::string month_name() const;
    
    virtual Date & operator++() = 0;
    virtual Date & operator--() = 0;
    virtual Date & operator+=(const int & a) = 0;
    virtual Date & operator-=(const int & a) = 0;

    virtual Date & add_month(int n = 1) = 0;
    virtual Date & add_year(int n = 1) = 0;
    
    
    bool operator==(const Date & date) const;
    bool operator!=(const Date & date) const;
    bool operator<(const Date & date) const;
    bool operator<=(const Date & date) const;
    bool operator>(const Date & date) const;
    bool operator>=(const Date & date) const;
    
    // Copy operator
    virtual Date & operator=(const Date & d) = 0;
    // Assignment operator
    virtual Date & operator=(Date && d) = 0;
    
    int operator-(const Date & date) const;
    
    virtual int mod_julian_day() const = 0;
    

protected:
    int _year;
    int _month;
    int _day;
    std::string _week_day_name;
    std::string _month_name;
    virtual bool leap_year(int & y) const = 0;
    

    
    
};

std::ostream & operator<<(std::ostream & os, const Date & d); // TODO maybe?

#endif /* defined(__lab2__Date__) */
