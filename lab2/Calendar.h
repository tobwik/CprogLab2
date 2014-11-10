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
#include <map>
#include <stdexcept>
#include <utility>
#include <typeinfo>

namespace lab2 {
    
    template <class T>
    class Calendar {
        
    public:
        
        struct Event {
            std::string name;
            
            Event() {
                
            }

            Event(std::string n) {
                name = n;
            }

            // bool operator==(const Event & event) const{
            //     if (name.compare(event.name) == 0)
            //         return true;
            //     return false;
            // }

            // bool operator!=(const Event & event) const{
            //     if (name.compare(event.name) == 0)
            //         return false;
            //     return true;   
            // }

            // bool operator<(const Event & event) const{
            //     if (name < event.name)
            //         return true;
            //     return false;
            // }

            // bool operator<=(const Event & event) const{
            //     if (name <= event.name)
            //         return true;
            //     return false;
            // }

            // bool operator>(const Event & event) const{
            //     if (name > event.name)
            //         return true;
            //     return false;
            // }

            // bool operator>=(const Event & event) const{
            //     if (name >= event.name)
            //         return true;
            //     return false;
            // }
        

        };
        
        Calendar();
//        Calendar(const Calendar & c);
        template <typename U> Calendar(const Calendar<U> & c);

        // Calendar & operator=(Calendar &);
        template <typename U> Calendar & operator=(Calendar<U> &);
        
        const bool set_date(int, int, int);
        const bool set_month(int);
        
        bool add_event(std::string, int, int, int);
        bool add_event(std::string);
        bool add_event(std::string, int);
        bool add_event(std::string, int, int);
        
        bool remove_event(std::string, int, int, int);
        bool remove_event(std::string);
        bool remove_event(std::string, int);
        bool remove_event(std::string, int, int);

        template <typename ST>
        friend std::ostream& operator<<(std::ostream & os, const Calendar<ST> & c); // TODO maybe?     
        
        T cDate;
        std::multimap<T, Event> events;
//    private:
        
    };

    template <typename ST>
    std::ostream & operator<<(std::ostream & os, const Calendar<ST> & c) {
        for (auto it = c.events.begin(); it != c.events.end(); ++it) {
            // os << it->first << " : " << it->second << std::endl;
            if (c.cDate < it->first)
            {
                os << it->first.year() << "-" << (it->first.month() < 10 ? "0" : "") << it->first.month() << "-" << (it->first.day() < 10 ? "0" : "") << it->first.day();
                os << " : " << it->second.name << std::endl;
            }
        }
        return os;
    }
    
    template <class T>
    Calendar<T>::Calendar() : cDate() {}
    
//    template <class T>
//    Calendar<T>::Calendar(const Calendar & c) : cDate(c.cDate) {
//        for (auto it = c.events.begin(); it != c.events.end(); ++it) {
//            std::pair<T, Event> p;
//            p.first = T(it->first);
//            p.second.set_name(it->second.name);
//            events.insert(p);
//        }
//    }

    template <class T>
    template <class U>
    Calendar<T>::Calendar(const Calendar<U> & c) : cDate(c.cDate) {
        for (auto it = c.events.begin(); it != c.events.end(); ++it) {
            std::pair<T, Event> p;
            p.first = T(it->first);
            Event e(it->second.name);
//            p.second(it->second.name);
            p.second = e;
            events.insert(p);
//            events.insert(std::pair<T, Event>(T(it->first), it->second));
        }
    }

//    template <class T>
//    Calendar<T>::Calendar(const Calendar & c) : cDate(c.cDate) {
//        for (typename std::set<std::pair<T, Event>>::iterator it = c.events.begin(); it != c.events.end(); ++it) {
//            events.insert(std::pair<T, Event>(it->first, it->second));
//        }
//    }

    // template <class T, class S>
    // Calendar<T>::Calendar(const Calendar<S> & c) : cDate(c.cDate){
    //     for (typename std::set<std::pair<T, Event>>::iterator it = c.events.begin(); it != c.events.end(); ++it) {
    //         events.insert(std::pair<T, Event>(it->first, it->second));
    //     }
    // }
    
    // template <class T>
    // Calendar<T> & Calendar<T>::operator=(Calendar & c) {
    //     cDate = c.cDate;
    //     events.clear();
        
    //     for (typename std::set<std::pair<T, Event>>::iterator it = c.events.begin(); it != c.events.end(); ++it) {
    //         events.insert(std::pair<T, Event>(it->first, it->second));
    //     }
        
    //     return *this;
    // }

    template <class T>
    template <class U>
    Calendar<T> & Calendar<T>::operator=(Calendar<U> & c) {
        cDate = c.cDate;
        events.clear();
        
        for (auto it = c.events.begin(); it != c.events.end(); ++it) {
            std::pair<T, Event> p;
            p.first = T(it->first);
            Event e(it->second.name);
//            p.second(it->second.name);
            p.second = e;
            events.insert(p);
            // events.insert(std::pair<T, Event>(it->first, it->second));
        }
        
        return *this;
    }
    
    template <class T>
    const bool Calendar<T>::set_date(int year, int month, int day) {
        try { cDate = T(year, month, day);
        } catch (std::out_of_range) { return false; }
        return true;
    }
    
    template <class T>
    const bool Calendar<T>::set_month(int month) {
        try { cDate = T(cDate.year(), month, cDate.day());
        } catch (std::out_of_range) { return false; }
        return true;
    }

    template <class T>
    bool Calendar<T>::add_event(std::string name) {
        return add_event(name, cDate.day());
    }

    template <class T>
    bool Calendar<T>::add_event(std::string name, int day) {
        return add_event(name, day, cDate.month());
    }

    template <class T>
    bool Calendar<T>::add_event(std::string name, int day, int month) {
        return add_event(name, day, month, cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::add_event(std::string name, int day, int month, int year) {
        try {
            T date(year, month, day);
            Event e(name); 

            // Check if event is already existing
            for (auto it = events.begin(); it != events.end(); ++it) {
                if (it->first == date && it->second.name == e.name) return false;
            }
            events.insert(std::pair<T, Event>(date, e));
            return true;
            
        } catch (std::out_of_range) {
            return false;
        }
    }

    template <class T>
    bool Calendar<T>::remove_event(std::string name) {
        return remove_event(name, cDate.day());
    }

    template <class T>
    bool Calendar<T>::remove_event(std::string name, int day) {
        return remove_event(name, day, cDate.month());
    }

    template <class T>
    bool Calendar<T>::remove_event(std::string name, int day, int month) {
        return remove_event(name, day, month, cDate.year());
    }
    
    template <class T>
    bool Calendar<T>::remove_event(std::string name, int day, int month, int year) {
        try {
            T date(year, month, day);
            for (auto it = events.begin(); it != events.end(); ++it) {
                Event e = it->second;
                if (it->first == date && it->second.name == name) {
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
