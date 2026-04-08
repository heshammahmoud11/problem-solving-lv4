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

bool isLeap(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getMonthDays(short month, short year)
{
    if(month < 1 || month > 12) return 0;
    short monthArr[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? ((isLeap(year) ? 29 : 28)) : monthArr[month];
}

bool isDate1_before_Date2(stDate date1, stDate date2)
{

 return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)):false );  

}

bool lastDay_N_Month(stDate date)
{
    return (date.day == getMonthDays(date.month, date.year));
}
bool lastMonth_N_Year(short month)
{
    return (month == 12);
}

stDate decreaseDate_By_1Day(stDate date)
{
    if(date.day > 1)
    {
        date.day--;
    }
    else if(date.month > 1)
    {
        date.day = getMonthDays(date.month - 1, date.year);
        date.month--;
    }
    else
    {
        date.day = 31;
        date.month = 12;
        date.year--;
    }

    return date;
}

int getDifference_N_Dates(stDate date1, stDate date2, bool includeEndDay = false)
{
    int days = 0;

    while (!isDate1_before_Date2(date1, date2))
    {
        days--;
        date1 = decreaseDate_By_1Day(date1);
    }

    return  includeEndDay ? days : ++days;
}

stDate getSystemDate()
{
    stDate date; 
    time_t t = time(0);
    tm* now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    return date;
}

int main()
{

    stDate date1 = readFullData();
    stDate date2 = readFullData();

    cout << "Diff Age in Days: " << getDifference_N_Dates(date1, date2) << " Day(s)\n";
    cout << "Diff Age in Days Include The End Day: " << getDifference_N_Dates(date1, date2, true) << " Day(s)\n";

    return 0;
}
