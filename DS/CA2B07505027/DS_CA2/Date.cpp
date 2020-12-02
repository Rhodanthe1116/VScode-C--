/*
    Date class

    @Author:       HAN-WEN, CHANG
    @ID:           B075050527
    @Department:   Engineering Science and Ocean Engineering
    @Affiliation:  National Taiwan University

    Date.cpp
*/

#include "Date.h"

/** 
   *  Constructs a Date with the given month, day and year.   If the date is
   *  not valid, the entire program will halt with an error message.
   *  @param month is a month, numbered in the range 1...12.
   *  @param day is between 1 and the number of days in the given month.
   *  @param year is the year in question, with no digits omitted.
   *
   *  Grade: 15%
   */
Date::Date(int month, int day, int year)
{
    // Check
    if (!isValidDate(month, day, year)) {
        cout << "The date is not a valid date" << endl;
        exit(0);
    }

    this->month = month;
    this->day = day;
    this->year = year;
}

/** 
   *  Constructs a Date object corresponding to the given string.
   *  @param s should be a string of the form "month/day/year" where month must
   *  be one or two digits, day must be one or two digits, and year must be
   *  between 1 and 4 digits.  If s does not match these requirements or is not
   *  a valid date, the program halts with an error message.
   *
   *  Grade: 30%
   */
Date::Date(const string& s)
{
    // Find slash "/"
    int slash1_pos = s.find("/");
    int slash2_pos = s.find("/", slash1_pos + 1);

    // Error
    if (slash1_pos == string::npos || slash2_pos == string::npos) {
        cout << "format error" << endl;
        exit(0);
    }

    // Split month, day, year
    int m = stoi(s.substr(0, slash1_pos - 0));
    int d = stoi(s.substr(slash1_pos + 1, slash2_pos - slash1_pos - 1));
    int y = stoi(s.substr(slash2_pos + 1, s.length() - slash2_pos - 1));

    //Check
    if (!isValidDate(m, d, y)) {
        cout << "The date is not a valid date" << endl;
        exit(0);
    }

    year = y;
    month = m;
    day = d;
}

/** 
   *  Checks whether the given year is a leap year.
   *  @return true if and only if the input year is a leap year.
   *
   *  Grade: 10%
   */
bool Date::isLeapYear(int year)
{
    // Trivial
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

/** 
   *  Returns the number of days in a given month.
   *  @param month is a month, numbered in the range 1...12.
   *  @param year is the year in question, with no digits omitted.
   *  @return the number of days in the given month.
   *
   *  Grade: 10%
   */
int Date::daysInMonth(int month, int year)
{
    // Make a list
    if (month == 1) {
        return 31;
    } else if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 3) {
        return 31;
    } else if (month == 4) {
        return 30;
    } else if (month == 5) {
        return 31;
    } else if (month == 6) {
        return 30;
    } else if (month == 7) {
        return 31;
    } else if (month == 8) {
        return 31;
    } else if (month == 9) {
        return 30;
    } else if (month == 10) {
        return 31;
    } else if (month == 11) {
        return 30;
    } else if (month == 12) {
        return 31;
    }
}

/** 
   *  Checks whether the given date is valid.
   *  @return true if and only if month/day/year constitute a valid date.
   *
   *  Years prior to A.D. 1 are NOT valid.
   *
   *  Grade: 20%
   */
bool Date::isValidDate(int month, int day, int year)
{
    // Simple logic
    if (year < 1) {
        return false;
    }
    if (month < 1 || 12 < month) {
        return true;
    }
    if (day < 1 || daysInMonth(month, year) < day) {
        return false;
    }

    return true;
}

/** 
   *  Returns a string representation of this Date in the form month/day/year.
   *  The month, day, and year are expressed in full as integers; for example,
   *  10/17/2010 or 5/11/258.
   *  @return a String representation of this Date.
   *
   *  Grade: 20%
   */
string Date::toString()
{
    string str = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    return str;
}

/** 
   *  Determines whether this Date is before the Date d.
   *  @return true if and only if this Date is before d.
   *
   *  Grade: 10%
   */
bool Date::isBefore(const Date& d)
{
    // List all condition
    if (year < d.year) {
        return true;
    } else if (year == d.year) {
        if (month < d.month) {
            return true;
        } else if (month == d.month) {
            if (day < d.day) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

/** 
   *  Determines whether this Date is after the Date d.
   *  @return true if and only if this Date is after d.
   *
   *  Grade: 10%
   */
bool Date::isAfter(const Date& d)
{
    return isBefore(d) or isEqual(d) ? false : true;
}

/** 
   *  Determines whether this Date is equal to the Date d.
   *  @return true if and only if this Date is the same as d.
   *
   *  Grade: 10%
   */
bool Date::isEqual(const Date& d)
{
    if (year == d.year && month == d.month && day == d.day) {
        return true;
    }
    return false;
}

/** 
   *  Returns the number of this Date in the year.
   *  @return a number n in the range 1...366, inclusive, such that this Date
   *  is the nth day of its year.  (366 is only used for December 31 in a leap
   *  year.)
   *
   *  Grade: 15%
   */
int Date::dayInYear()
{
    // Simple calculate
    int sum = 0;
    for (int i_month = 1; i_month <= month - 1; i_month++) {
        sum += daysInMonth(i_month, year);
    }
    sum += day;
    return sum;
}

/** Determines the difference in days between d and this Date.  For example,
   *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
   *  If this Date occurs before d, the result is negative.
   *  @return the difference in days between d and this Date.
   *
   *  Grade: 10%
   */
int Date::difference(const Date& d)
{
    Date dtmp(d);
    if (year < dtmp.year) {
        // Swap
        return -dtmp.difference(*this);
    } else if (year == dtmp.year) {
        // If equal, calculating is easy.
        return dayInYear() - dtmp.dayInYear();
    } else {
        // If not equal, do recurrsion.
        Date PreviousDate(12, 31, year - 1);
        return PreviousDate.difference(dtmp) + dayInYear();
    }
}
