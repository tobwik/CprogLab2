//
//  Date.cpp
//  lab2
//
//  Created by Tobias Wikström on 04/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#include "Date.h"

int _year;
int _month;
int _day;
std::string _week_day_name;
std::string _month_name;

Date::Date(int y, int m, int d) {
    _year = y;
    _month = m;
    _day = d;
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

std::string Date::week_day_name() const {
    return _week_day_name;
}
std::string Date::month_name() const {
    return _month_name;
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
    if (mod_julian_day() > date.mod_julian_day())
        return mod_julian_day() - date.mod_julian_day();
    return date.mod_julian_day() - mod_julian_day();
}



