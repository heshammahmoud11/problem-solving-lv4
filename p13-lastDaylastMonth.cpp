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

short getDaysofMonth(short month, short year)
{
    if(month < 1 && month > 12) return 0;
    short monthArr[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (leapYear(year) ? 28 : 29) : monthArr[month];
}

void checkLastDay(stDate date)
{
    short monthDays = getDaysofMonth(date.month, date.year); // retunr the number of days in this month

    if(date.day == monthDays)
       cout << "Yes,this is the last Day in month\n";
    else 
      cout << "No, this is not the last Day\n";
}
void checkLastMonth(stDate date)
{
    short monthDays = getDaysofMonth(date.month, date.year); // retunr the number of days in this month

    if(date.month == 12) 
       cout << "Yes, this is the last month in year\n";
    else 
       cout << "No, this is not the last month in year\n";
}

int main()
{
    stDate date = readFullData(); 

    checkLastDay(date);
    checkLastMonth(date);

    return 0;
}