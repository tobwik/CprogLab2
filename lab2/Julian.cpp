//
//  Julian.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include "Julian.h"

//int _year;
//int _month;
//int _day;
//std::string _week_day_name;
//std::string _month_name;

int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Julian::Julian() : Date(1858, 11, 17){
}

Julian::Julian(int y, int m, int d) : Date(y,m,d){
//    _year = y;
//    _month = m;
//    _day = d;
}

Julian::Julian(const Date & d) : Date(1858, 11, 17){
    int j_day = d.mod_julian_day();
//    _year = 1858;
//    _month = 11;
//    _day = 17;
    change_date(j_day);
}

Julian::~Julian() {
    
}
Date & Julian::operator++() {
    change_date(1);
    return *this;
}
Date & Julian::operator--() {
    change_date(-1);
    return *this;
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
    _year = 1858;
    _month = 11;
    _day = 17;
    change_date(j_day);
    return *this;
    
}

Date & Julian::operator=(Date && date) {
    if (&date == this)
        return *this;

    int j_day = date.mod_julian_day();
    _year = 1858;
    _month = 11;
    _day = 17;
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
                change_date(364);
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
                change_date(-366); // TODO kan vara fuck
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
                _year++;
            }
            _day += days_this_month();
        }
    }
    
    
}

int Julian::week_day() const {
    return mod_julian_day() % 7 + 3;
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
    if (m > 12)
        throw std::out_of_range("Month out of range");
    if (m == 0) {
        m = 12;
        y--;
    } else if (m == 13) {
        m = 1;
        y++;
    }
    if (y % 4 == 0 && m == 2)
        return 29;
    return days_month[m-1];
}
int Julian::months_per_year() const {
    return 12;
}

int Julian::mod_julian_day() const { // nice
    int j_year = 1858;
    int j_month = 11;
    int j_day = 17;
    
    int m = _month;
    
    if (m == 1 || m == 2) {
        m += 12;
    }
    
    return 365*(_year) + _year/4 + _day +  (153*m+8)/5 - (365*(j_year) + j_year/4 + j_day +  (153*j_month+8)/5);
}
