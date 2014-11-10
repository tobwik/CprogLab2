//
//  Calendar.h
//  lab2
//
//  Created by Tobias Wikström on 05/11/14.
//  Copyright (c) 2014 Tobias Wikström. All rights reserved.
//

#ifndef __lab2__Calendar__
#define __lab2__Calendar__

#include <iostream>
#include <set>

namespace lab2 {
    
    template <class T>
    class Calendar {
        
    public:
        
        struct Event {
            std::string name;
            T date;
        };
        
        Calendar();
        
        Calendar & operator=(const Calendar &);
        
        const bool set_date(int &, int &, int &);
        const bool set_month(int &);
        
        bool add_event(std::string, int, int, int);
        bool add_event(std::string);
        bool add_event(std::string, int);
        bool add_event(std::string, int, int);
        
        bool remove_event(std::string, int, int, int);
        bool remove_event(std::string);
        bool remove_event(std::string, int);
        bool remove_event(std::string, int, int);
        
        
    private:
        T cDate;
        std::set<std::pair<T, Event>> events;
        
    };
    
    template <class T>
    Calendar<T>::Calendar() : cDate() {}
    
    template <class T>
    Calendar<T> & Calendar<T>::operator=(const Calendar<T> & c) {
        cDate = c.cDate;
        events.clear();
        
        for (typename std::set<std::pair<T, Event>>::iterator it = c.events.begin(); it != c.events.end(); ++it) {
            events.insert(std::pair<T, Event>(it->first, it->second));
        }
        
        return *this;
    }
    
    template <class T>
    const bool Calendar<T>::set_date(int & year, int & month, int & day) {
        try { cDate = T(year, month, day);
        } catch (std::out_of_range) { return false; }
        return true;
    }
    
    template <class T>
    const bool Calendar<T>::set_month(int & month) {
        try { cDate = T(cDate.year(), month, cDate.day());
        } catch (std::out_of_range) { return false; }
        return true;
    }
    
    template <class T>
    bool Calendar<T>::add_event(std::string name) {
        return add_event(name, cDate.day(), cDate.month(), cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::add_event(std::string name, int day) {
        return add_event(name, day, cDate.month(), cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::add_event(std::string name, int day, int month) {
        return add_event(name, day, month, cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::add_event(std::string name, int day, int month, int year) {
        try {
            T date(year, month, day);
            Event e(date, name); // TODO fixa konstruktorer till event
            
            // Check if event is already existing
            for (typename std::set<std::pair<T, Event>>::iterator it = events.begin(); it != events.end(); ++it) {
                if (it->first == e.date && it->second.name == e.name) return false;
            }
            events.insert(std::pair<T, Event>(e.date, e));
            return true;
            
        } catch (std::out_of_range) {
            return false;
        }
    }
    
    template <class T>
    bool Calendar<T>::remove_event(std::string name) {
        return remove_event(name, cDate.day(), cDate.month(), cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::remove_event(std::string name, int day) {
        return remove_event(name, day, cDate.month(), cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::remove_event(std::string name, int day, int month) {
        return remove_event(name, day, month, cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::remove_event(std::string name, int day, int month, int year) {
        try {
            T date(year, month, day);
            
            for (typename std::set<std::pair<T, Event>>::iterator it = events.begin(); it != events.end(); ++it) {
                Event e = it->second;
                if (it->first == e.date && it->second.name == e.name) {
                    
                    events.erase(it);
                    
                    return true;
                }
            }
            
        } catch (std::out_of_range) {
            return false;
        }
        return false;
    }
}
#endif /* defined(__lab2__Calendar__) */
