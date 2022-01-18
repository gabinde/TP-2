#include <iostream>
#include <assert.h>

#ifndef DATE_H
#define DATE_H

namespace date {
   class Date {
   public:
      Date(int month=1, int day=1,int year = 1900);
      int month() const; // fait 
      int day() const;// fait
      int year() const; //fait
      void updateYear(int year); // fait
      void updateMonth(int month); // fait
      void updateDay(int day); //fait
      void next(); //fait
      void back(); //fait
   private:
      int _month;
      int _day;
      int _year;

   };

   bool isDate(int month, int day, int year); //fait
   int getDaysInMonth(Date d); //fait
   int dayOfYear(Date d); //fait
   std::string toString(Date d); //fait


   bool operator == (const Date&, const Date&); //fait
   bool operator != (const Date&, const Date&); //fait
   bool operator < (const Date&, const Date&); //fait
   bool operator > (const Date&, const Date&); //fait
   bool operator <= (const Date&, const Date&); //fait
   bool operator >= (const Date&, const Date&); //fait

   Date operator + (const Date& date, const int days); // date + integer
   Date operator + (const int days, const Date& date); // integer + date
   Date operator - (const Date& date, const int days); // date - integer

   Date operator ++ (Date& date); // prefix increment: ++date
   Date operator -- (Date& date); // prefix decrement: --date
   Date operator ++ (Date& date, int); // use int paramater for postfix increment: date++
   Date operator -- (Date& date, int); // use int paramater for postfix decrement: date--
} // date

#endif // DATE_H