#include<iostream>
#include<ctime>
using namespace std;



struct stDate
{
    short day;
    short month;
    short year;
};

bool isLeap(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getMonthDays(short month, short year) 
{
    if(month < 1 || month > 12) return 0;
    short monthArr[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeap(year) ? 29 : 28) : monthArr[month];
}

short getYearDays(short year)
{
    return isLeap(year) ? 366 : 365; 
}
short numberOfDays_from_BeginingYear(short day, short month, short year)
{
    int sumDays = 0;
    for(int i = 1; i <= (month - 1); i++)
    {
        sumDays += getMonthDays(i, year);
    }
    return sumDays + day;
}

stDate systemDate()
{
    stDate date;

    time_t t =  time(0);
    tm* now = localtime(&t);

    date.year = now-> tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    return date;
}

short dayOrder_N_Week(short day, short month, short year)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7;
}

string dayName(short dayOrder)
{
    string dayName[7] {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return dayName[dayOrder];
}

bool isEnd_of_Week(string dayName)
{
    return (dayName == "Sat");
}

bool isWeekEnd(string dName)
{
    return (dName == "Fri" || dName == "Sat");
}

bool isBusinessDay(string dayName)
{
    return !isWeekEnd(dayName);
}

short days2End_of_Week(short day)
{
    return 6 - day ;
}

short days2End_of_Month(short monthDays, short today)
{
    return monthDays - today;
}
short days2End_of_Year(short yearDays, short beginingDays)
{
    return yearDays - beginingDays;
;
}


int main()
{
    stDate date = systemDate();
    short dayOrder = dayOrder_N_Week(date.day, date.month, date.year);
    string dName = dayName(dayOrder);
    short monthDays = getMonthDays(date.month, date.year);
    short yearDays = getYearDays(date.year);
    short days_from_begining = numberOfDays_from_BeginingYear(date.day, date.month, date.year);

    cout << "\nToday is " << dName << " , " << date.day << " / " << date.month << " / " << date.year << endl;

    cout << "\nis it End of Week ? \n";
    if(isEnd_of_Week(dName))
        cout << "Yes, End of Week\n";
    else
        cout << "No, Not End of Week\n";
    
    cout << "\nIs it Weekend ?\n";
    if(isWeekEnd(dName))
        cout << "Yes, it's Weekend\n";
    else 
        cout << "No, it's not weekend\n";
    
    cout << "\nIs it Business Day?\n";
    if(isBusinessDay(dName))
         cout << "Yes, it's Business Day\n";
    else
         cout << "No, it's Not business Day\n";

    cout << "\nDays Until End of Week: " << days2End_of_Week(dayOrder) << " Day(s)\n";
    cout << "\nDays Until End of Month: " << days2End_of_Month(monthDays, date.day) << " Day(s)\n";
    cout << "\nDays Until End of Year: " << days2End_of_Year(yearDays, days_from_begining) << " Day(s)\n";
    return 0;
}