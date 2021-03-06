//
//  Date.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include "Date.h"
using namespace lab2;
int _year;
int _month;
int _day;

Date::Date(int y, int m, int d) {
    _year = y;
    _month = m;
    _day = d;
}

Date::Date(Date const& d) {
    _year = d.year();
    _month = d.month();
    _day = d.day();
}
int Date::year() const {
    return _year;
}
int Date::month() const {
    return _month;
}
int Date::day() const {
    return _day;
}

bool Date::operator==(const Date & date) const {
    return mod_julian_day() == date.mod_julian_day();
}
bool Date::operator!=(const Date & date) const {
    return mod_julian_day() != date.mod_julian_day();
}
bool Date::operator<(const Date & date) const {
    return mod_julian_day() < date.mod_julian_day();
}
bool Date::operator<=(const Date & date) const {
    return mod_julian_day() <= date.mod_julian_day();
}
bool Date::operator>(const Date & date) const {
    return mod_julian_day() > date.mod_julian_day();
}
bool Date::operator>=(const Date & date) const {
    return mod_julian_day() >= date.mod_julian_day();
}

int Date::operator-(const Date & date) const {
    return mod_julian_day() - date.mod_julian_day();
}

std::ostream & operator<<(std::ostream & os, const Date & d) {
    return os << d.year() << "-" << (d.month() < 10 ? "0" : "") << d.month() << "-" << (d.day() < 10 ? "0" : "") << d.day();
}


