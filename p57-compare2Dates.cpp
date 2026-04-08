#include<iostream>
using namespace std; 



struct stDate
{
    short day;
    short month;
    short year;
};


short getYear()
{
    short year;
    cout << "Please Enter the Year: ";
    cin >> year;
    return year;
}
short getMonth()
{
    short month;
    cout << "Please Enter the Month: ";
    cin >> month;
    return month;
}
short getDay()
{
    short day;
    cout << "Please Enter the Day: ";
    cin >> day;
    return day;
}
bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
stDate readFullDate()
{
    stDate date;
    date.day = getDay();
    date.month = getMonth();
    date.year = getYear();
    return date;
}
short getMonthDays(short month, short year)
{
    if(month < 1 || month > 12) return 0;
    short monthArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monthArr[month];
}

bool isDate1_After_Date2(stDate date1, stDate date2)
{
    return (date1.year > date2.year) ? true
         : (date1.year < date2.year) ? false
         : (date1.month > date2.month) ? true
         : (date1.month < date2.month) ? false
         : (date1.day > date2.day);
         // Other Solution -> Fast
         // return (!isDate1_before_Date2(stDate date1, stDate date2) && isDate1_Equal_Date2(stDate date1, stDate date2))
}
bool isDate1_before_Date2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true 
         : (date1.year > date2.year) ? false
         : (date1.month < date2.month) ? true
         : (date1.month > date2.month) ? false
         : (date1.day < date2.day);
}

bool isDate1_Equal_Date2(stDate date1, stDate date2)
{
    return (date1.year == date2.year) ? (date1.month == date2.month) ? (date1.day == date2.day) : false : false;
}
enum enCompareDates { before = -1, equal = 0, after = 1};

enCompareDates compareDates(stDate date1, stDate date2)
{
    if(isDate1_After_Date2(date1, date2))
        return enCompareDates::after;

    if(isDate1_before_Date2(date1, date2))
        return enCompareDates::before;

    return enCompareDates::equal;
     
}

int main()
{
    stDate date1 = readFullDate();
    cout << endl;
    stDate date2 = readFullDate();

    
    cout << "\n Compare Date : " << compareDates(date1, date2) << endl;
    return 0;
}