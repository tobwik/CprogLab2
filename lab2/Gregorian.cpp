//
//  Gregorian.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include "Gregorian.h"

using namespace lab2;

int g_days_month[12];
int gyear = 1858;
int gmonth = 11;
int gday = 17;

Gregorian::Gregorian() : Date(gyear, gmonth, gday){
    init();
}

Gregorian::Gregorian(int y, int m, int d) : Date(y,m,d){
    init();
    if (m > months_per_year() || m < 1) {
        throw std::out_of_range("Month out of range");
    }
    if (d > days_in_month(m, y) || d < 1) {
        throw std::out_of_range("Day out of range");
    }
    //    _year = y;
    //    _month = m;
    //    _day = d;
}

Gregorian::Gregorian(const Date & d) : Date(gyear, gmonth, gday){
    init();
    int j_day = d.mod_julian_day();
    change_date(j_day);
}

Gregorian::Gregorian(const Gregorian & g) : Date(gyear, gmonth, gday){
    init();
    int j_day = g.mod_julian_day();
    change_date(j_day);
}

Gregorian::~Gregorian() {
    
}

void Gregorian::init() {
    int dm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::copy(dm, dm+12, g_days_month);
}

Date & Gregorian::operator++() {
    change_date(1);
    return *this;
}
Gregorian Gregorian::operator++(int i) {
    change_date(1);
    Gregorian g(*this);
    return g;
}
Date & Gregorian::operator--() {
    change_date(-1);
    return *this;
}
Gregorian Gregorian::operator--(int i) {
    change_date(-1);
    Gregorian g(*this);
    return g;
}
Date & Gregorian::operator+=(const int & a) {
    change_date(a);
    return *this;
}
Date & Gregorian::operator-=(const int & a) {
    change_date(-a);
    return *this;
}

Date & Gregorian::operator=(const Date & date) {
    if (&date == this)
        return *this;
    
    int j_day = date.mod_julian_day();
    _year = gyear;
    _month = gmonth;
    _day = gday;
    change_date(j_day);
    return *this;
    
}

Date & Gregorian::operator=(Date && date) {
    if (&date == this)
        return *this;
    
    int j_day = date.mod_julian_day();
    _year = gyear;
    _month = gmonth;
    _day = gday;
    change_date(j_day);
    return *this;
}

Date & Gregorian::add_year(int n) {
    
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
        while (-n > 4) {
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

Date & Gregorian::add_month(int n) {
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


void Gregorian::change_date(const int & d) {
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
                _year++;
            }
            _day += days_this_month();
        }
    }
    
    
}

int Gregorian::week_day() const {
    return (mod_julian_day() + 2) % days_per_week() + 1;
}
int Gregorian::days_per_week() const {
    return 7;
    
}
int Gregorian::days_this_month() const {
    return days_in_month(_month, _year);
}

bool Gregorian::leap_year(int & y) const {
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        return true;
    return false;
}

int Gregorian::days_in_month(int m, int y) const {
    if (m == 0) {
        m = 12;
        y--;
    } else if (m == 13) {
        m = 1;
        y++;
    }
    if (leap_year(y) && m == 2)
        return 29;
    return g_days_month[m-1];
}
int Gregorian::months_per_year() const {
    return 12;
}

int Gregorian::mod_julian_day() const { // nice
    int m = _month;
    int y = _year;
    
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    
    int r_value = 365*(y) + y/4 - y/100 + y/400 + _day +  (153*m+8)/5 - (365*(gyear) + gyear/4 - gyear/100 + gyear/400 + gday +  (153*gmonth+8)/5);
    
    return r_value;
}
