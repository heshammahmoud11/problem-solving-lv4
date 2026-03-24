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

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getDaysofMonth(short month, short year)
{
    if(month < 1 || month < 12) return 0;
    short monthArr[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monthArr[month];
}

short numberOfDays_From_BeginngYear(short day, short month, short year)
{
    short totalDays = 0;

    for(int i = 1; i <= (month - 1); i++)
    {
        totalDays += getDaysofMonth(i, year);
    }
    return totalDays + day;
}

bool compare2Date(stDate date1, stDate date2)
{
    short totalDate1 = numberOfDays_From_BeginngYear(date1.day, date1.month, date1.year);
    short totalDate2 = numberOfDays_From_BeginngYear(date2.day, date2.month, date2.year);

    if(totalDate1 > totalDate2) return true;
    else return false;
}


stDate readFullData()
{
    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
}

int main()
{
    cout << "Enter Date One\n";
    stDate date1 = readFullData();
    cout << "Enter Date Two\n";
    stDate date2 = readFullData();

    if(compare2Date(date1, date2)) cout << "Date 1 Larger Than date 2\n";
    else cout << "Date 1 less than date 2\n";
    return 0;                         
}