#include<iostream> 
using namespace std;

short getDay()
{
    short day; 
    cout << "Enter the Days: "; 
    cin >> day; 
    return day; 
}
short getMonth()
{
    short month; 
    cout << "Enter a Month: "; 
    cin >> month;
    return month;
}
short getYear()
{
    short year; 
    cout << "Enter a Year: ";
    cin >> year; 
    return year; 
}

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// This function return the number of days in a month.
short getMonthDays(short month, short year)
{
    short monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (isLeapYear(year) ? 29 : 28): monthDays[month] ;
}

short beginingDays(short day, short month, short year)
{
    short sumDays = 0;
    for(int i = 1; i <= (month - 1); i++)
    {
        sumDays += getMonthDays(i, year);
    }
    return sumDays + day;
}

int main()
{
    short d = getDay();
    short m = getMonth();
    short y = getYear(); 

    cout << "The Begining Days from Year: " <<  beginingDays(d, m, y) << endl;
    return 0;
}