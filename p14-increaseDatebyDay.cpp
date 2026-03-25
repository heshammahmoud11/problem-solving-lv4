#include<iostream>
using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

short readDay()
{
    short d;
    cout << "Enter a Day: ";
    cin >> d;
    return d;
}
short readMonth()
{
    short m;
    cout << "Enter a Month: ";
    cin >> m;
    return m;
}
short readYear()
{
    short y;
    cout << "Enter a Year: ";
    cin >> y;
    return y;
}

stDate readFullData()
{
 
    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
}

bool leapYear(short year) 
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getMonthDays(short month, short year)
{
    if(month < 1 || month > 12) return 0;
    short monthArr[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (leapYear(year) ? 29 : 28 ) : monthArr[month];
}

stDate addNewDay( stDate date)
{
    short monDays = getMonthDays(date.month, date.year);

    if(date.day < monDays) // last day in the month
    {
        date.day++;
    } 
    else if(date.month < 12)  // day is = last day, month != 12
    {   
        date.day = 1;
        date.month++;
    }
    else
    {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    return date;
}

int main()
{
    stDate date = readFullData();

    stDate ans = addNewDay(date);
    cout << ans.day << " / " << ans.month << " / " << ans.year << endl; 

    return 0;
}