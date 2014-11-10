//
//  Julian.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include "Julian.h"
#include <time.h>
#include "kattistime.h"

using namespace lab2;

int j_days_month[12];
int jyear = 1858;
int jmonth = 11;
int jday = 5;

Julian::Julian() : Date(jyear, jmonth, jday){
    init();
    adjust();
}

void Julian::adjust() {
    time_t mytime;
    time(&mytime);
//    set_k_time(mytime);
    
    struct tm *t = gmtime(&mytime);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day   = t->tm_mday;
    
    _year = jyear;
    _month = jmonth;
    _day = jday;
    int changeValue = mod_julian_from_gregorian(year, month, day);
    change_date(changeValue);
}

Julian::Julian(int y, int m, int d) : Date(y,m,d){
    init();
    if (m > months_per_year() || m < 1) {
        throw std::out_of_range("exception_in_constructor");
    }
    if (d > days_in_month(m, y) || d < 1) {
        throw std::out_of_range("exception_in_constructor");
    }
}

Julian::Julian(const Date & d) : Date(jyear, jmonth, jday){
    init();
    int j_day = d.mod_julian_day();
    change_date(j_day);
}

Julian::Julian(const Date * d) : Date(jyear, jmonth, jday){
    init();
    int j_day = d->mod_julian_day();
    change_date(j_day);
}

Julian::Julian(const Julian & j) : Date(jyear, jmonth, jday){
    init();
    int j_day = j.mod_julian_day();
    change_date(j_day);
}

Julian::~Julian() {
    
}

void Julian::init() {
    int dm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::copy(dm, dm+12, j_days_month);
}

Date & Julian::operator++() {
    change_date(1);
    return *this;
}
Julian Julian::operator++(int i) {
    change_date(1);
    Julian j(*this);
    return j;
}
Date & Julian::operator--() {
    change_date(-1);
    return *this;
}
Julian Julian::operator--(int i) {
    change_date(-1);
    Julian j(*this);
    return j;
}
Date & Julian::operator+=(const int & a) {
    change_date(a);
    return *this;
}
Date & Julian::operator-=(const int & a) {
    change_date(-a);
    return *this;
}

Date & Julian::operator=(const Date & date) {
    if (&date == this)
        return *this;
    
    int j_day = date.mod_julian_day();
    _year = jyear;
    _month = jmonth;
    _day = jday;
    change_date(j_day);
    return *this;
    
}

Date & Julian::operator=(const Julian & date) {
    if (&date == this)
        return *this;
    
    int j_day = date.mod_julian_day();
    _year = jyear;
    _month = jmonth;
    _day = jday;
    change_date(j_day);
    return *this;
    
}

Date & Julian::operator=(Date && date) {
    if (&date == this)
        return *this;

    int j_day = date.mod_julian_day();
    _year = jyear;
    _month = jmonth;
    _day = jday;
    change_date(j_day);
    return *this;
}

Date & Julian::add_year(int n) {
    
    if (n > 0) {
        while (n >= 4) {
            _year += 4;
            n -= 4;
        }
        
        for (int i = 0; i < n; i++) {
            if (_day == 29 && _month == 2) {
                change_date(365);
            } else {
                _year++;
            }
        }
    } else {
        while (-n >= 4) {
            _year -= 4;
            n += 4;
        }
        
        for (int i = 0; i < -n; i++) {
            if (_day == 29 && _month == 2) {
                change_date(-366);
            } else {
                _year--;
            }
        }
    }
    return *this;
}

Date & Julian::add_month(int n) {
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            if (days_in_month(_month+1, _year) < _day) {
                change_date(30);
            } else {
                _month++;
                if (_month > months_per_year()) {
                    _month -= months_per_year();
                    _year++;
                }
            }
        }
    } else {
        for (int i = 0; i < -n; i++) {
            if (days_in_month(_month-1, _year) < _day) {
                change_date(-30);
            } else {
                _month--;
                if (_month < 1) {
                    _month += months_per_year();
                    _year--;
                }
            }
        }
    }
    return *this;
}


void Julian::change_date(const int & d) {
    _day += d;
    
    if (d > 0) {
        while (_day > days_this_month()) {            
            _day -= days_this_month();
            _month++;
            
            if (_month > months_per_year()) {
                _month -= months_per_year();
                _year++;
            }
        }
    } else {
        while (_day < 1) {
            _month--;
            
            if (_month < 1) {
                _month += months_per_year();
                _year--;
            }
            _day += days_this_month();
        }
    }
    
    
}

int Julian::week_day() const {
    int wd = (mod_julian_day() + 2) % days_per_week() + 1;
    return (wd < 1 ? wd + days_per_week() : wd);
}
int Julian::days_per_week() const {
    return 7;
    
}
int Julian::days_this_month() const {
    return days_in_month(_month, _year);
}

bool Julian::leap_year(int & y) const {
    if (y % 4 == 0)
        return true;
    return false;
}

int Julian::days_in_month(int m, int y) const {
    if (m == 0) {
        m = 12;
        y--;
    } else if (m == 13) {
        m = 1;
        y++;
    }
    if (y % 4 == 0 && m == 2)
        return 29;
    return j_days_month[m-1];
}
int Julian::months_per_year() const {
    return 12;
}

int Julian::mod_julian_day() const { // nice
    int m = _month;
    int y = _year;
    
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    
    int r_value = 365*(y) + y/4 + _day +  (153*m+8)/5 - (365*(jyear) + jyear/4 + jday +  (153*jmonth+8)/5);
    
    return r_value;
}

int Julian::mod_julian_day(int y, int m, int d) const {

    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    
    return 365*(y) + y/4 + d +  (153*m+8)/5 - (365*(jyear) + jyear/4 + jday +  (153*jmonth+8)/5);
    
}

int Julian::mod_julian_from_gregorian(int y, int m, int d) const {
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    
    return 365*(y) + y/4 - y/100 + y/400 + d +  (153*m+8)/5 - (365*(1858) + 1858/4 - 1858/100 + 1858/400 + 17 +  (153*11+8)/5);
}

std::string Julian::week_day_name() const {
    static std::string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    return days[week_day() - 1];
}

std::string Julian::month_name() const {
    static std::string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    return months[month() - 1];
}
