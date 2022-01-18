#include "date.h"
#include <assert.h> 

namespace date {
    Date::Date(int month, int day, int year) : 
    _month(month), 
    _day(day), 
    _year(year){
        bool status = isDate(month, day, year);
        assert(status && "Date is not valid");
    }

    int Date::year() const{
        return _year;
    }

    int Date::month() const {
    	return _month;
    }

    int Date::day() const {
    	return _day;
    }

    void Date::updateMonth(int month) {
        bool status = isDate(month, _day, _year);
        assert(status==true && "New month is not valid");
        _month = month;
    }

    void Date::updateDay(int day) {
        bool status = isDate(_month, day, _year);
        assert(status==true && "New day is not valid");
        _day = day;
    }

    void Date::updateYear(int year){
        bool status = isDate(_month, _day ,year);
        assert(status == true && "New year is not valid");
        _year = year;
    }


    void Date::next() {
        if ((_month==12) && (_day==31)) {
            _day=1;
            _month=1;
            _year+=1;
        }
        else if (_day==getDaysInMonth(_month)) {
            _day=1;
            _month++;
        }
        else {
            _day++;
        }
    }

    void Date::back() {
        if ((_month==1) && (_day==1)) {
            _day=31;
            _month=12;
            _year-=1;

        }
        else if (_day==1) {
            _month--;
            _day=getDaysInMonth(_month);
        }
        else {
            _day--;
        }
    }


    bool isDate(int month, int day, int year) {
        if ((day < 1) || (day>31)) return false;
        if ((month <1) || (month>12)) return false;
        if ((year%4 == 0) && ((month == 2) && (day > 29))) return false;
        if ((year%4 != 0) && ((month == 2) && (day > 28))) return false;
        if (((month == 4) || (month == 6) ||
            (month == 9) || (month == 11)) && (day > 30)) return false;
        return true;
    }

    int getDaysInMonth(Date d){
        assert((d.month() >=1) && (d.month()<=12) && ("Month is not valid"));
        if (( d.year()%4 == 0) && (d.month() == 2)) return 29;
        if (( d.year()%4 != 0) && (d.month() == 2)) return 29;
        if ((d.month() == 1 || d.month()== 3 || d.month() == 5 || d.month() == 7
        || d.month() == 8 || d.month() == 10 || d.month() == 12)) return 31;
        return 30;
    }

    int dayOfYear(Date d) {
        auto day=0;
        for (auto i=1;i<d.month();i++) {
            day+=getDaysInMonth(i);
        }
        day+= d.day();
        return day;
    }

    std::string toString(Date d) {
        return std::to_string(d.day()) + "/" + std::to_string(d.month()) + "/" + std::to_string(d.year()) ;
    }

    Date operator + (const Date& date, const int days) {
        if (days <0) { //if days <0, we call Date - (-days)
            return date - (-days);
        }
        Date tmp = date; // the current date
        int new_day = tmp.day() + days; // the new day is ok if new_day < end of month
        int new_month = tmp.month();
        int new_year = tmp.year();
        int days_in_month = getDaysInMonth(tmp.month());
        while (new_day > days_in_month) { // end of the month
            new_day -= days_in_month; // the day in the next month
            new_month++;
            if (new_month > 12) { // end of the year
                new_month = 1;
                new_year +=1;
            }
            tmp.updateMonth(new_month);
            tmp.updateYear(new_year);
            days_in_month = getDaysInMonth(tmp.month());
        }
        return Date(new_month, new_day, new_year);
    }

    Date operator + (const int days, const Date& date) {
        return date + days;
    }

    Date operator ++(Date& date) { // prefix increment
        date = date + 1;
        return date;
    }

    Date operator --(Date& date) { // prefix decrement
        date = date - 1;
        return date;
    }

    Date operator ++(Date& date, int) { // postfix increment
        Date tmp = date;
        date = tmp +1;
        return tmp;
    }

    Date operator --(Date& date, int) { // postfix decrement
        Date tmp = date;
        date = date - 1;
        return tmp;
    }

    Date operator - (const Date& date, const int days) {
        if (days <0) { //if days <0, we call Date + (-days)
            return date + (-days);
        }
        int new_month=date.month();
        int new_day = date.day()-days; // the new day is ok if > 0
        while (new_day <=0) {
            if (new_month==1) { // beginning of the year
                new_month=12; // in december
                new_day=31+new_day;
            }
            else { // other months than january
                int days_in_previous_month = getDaysInMonth(Date(new_month-1,1).month());
                new_day = days_in_previous_month+new_day;
                new_month--;
            }
        }
        return Date(new_month, new_day);
    }

    bool operator == (const Date& d1,const Date& d2) { // check for equality
        if( (d1.day()==d2.day()) && (d1.month()==d2.month()) && (d1.year() == d2.year())) {
            return true;
        }
    return false;
    }

    bool operator !=(const Date& d1, const Date& d2) {
        return !(d1==d2);
    }

    bool operator < (const Date& d1, const Date& d2) {
        if(d1.year()< d2.year()){
            return true;
        }
        if(d1.year()> d2.year()){
            return false;
        }
        if (d1.month()<d2.month()) {
            return true;
        }
        if (d1.month()>d2.month()) {
            return false;
        }  
        if ( d1.day()<d2.day()) {
            return true;
        }
        else{
            return false;
        }
    }


    bool operator > (const Date& d1, const Date& d2) {
        if (d1==d2) {
            return false;
        }
        if (d1<d2) {
            return false;
        }
        return true;
    }

    bool operator <=(const Date& d1, const Date& d2) {
        if (d1==d2) {
            return true;
        }
        return (d1<d2);
    }

    bool operator >=(const Date& d1, const Date& d2) {
        if (d1==d2) {
            return true;
        }
        return (d1>d2);
    }

}