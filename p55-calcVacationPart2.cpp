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

stDate increaseDate_by_1Day(stDate date)
{
    if(date.day < getMonthDays(date.month, date.year))
    {
        date.day++;
    }
    else if(date.month < 12)
    {
        date.day = 1;
        date.month++;
    }
    else
    {
        date.day = 1;
        date.month = 1;
        date. year++;       
    }

    return date;
}

short dayOrder_N_Week(short day, short month, short year) 
{
    short a, m, y;
    a = (14 - month) / 12;
    y = year - a;
    m = month + ( 12 * a) - 2;

     return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(stDate date)
{
    return  dayOrder_N_Week(date.day, date.month, date.year) ;
}

string dayName_N_Week(short dayOrder)
{
    string weekDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return weekDays[dayOrder]; 
}

bool isWeekEnd(stDate date)
{
    short index = dayOrder_N_Week(date.day, date.month, date.year);
    return (index == 5 || index == 6);
}
bool isBusinessDay(stDate date)
{
    return !isWeekEnd(date);
}
short readVacDays()
{
    short n;
    cout << "Enter How Many Days In Vacation: ";
    cin >> n;
    return n;
}

stDate calcVacationDays(stDate date, short vacDays)
{
    short cnt = 0;
    while(isWeekEnd(date))
    {
        date = increaseDate_by_1Day(date);
    }

    for(short i = 1; i <= vacDays + cnt; i++) // This is business day (Definatly)
    {
        date = increaseDate_by_1Day(date);
        if(isWeekEnd(date))
          cnt++;
    }
    // Check if return date is weekend, i have to skip this day.
    while(isWeekEnd(date))
    {
        date = increaseDate_by_1Day(date);
    }
    return date;
} 

int main()
{
    stDate date1 = readFullDate();
    short vacDays = readVacDays();

    stDate date = calcVacationDays(date1, vacDays ); 
    short dayOrder = DayOfWeekOrder(date);
    cout << "\nRturn to work Date: " << dayName_N_Week(dayOrder) << " , " << date.day << " / " << date.month << " / " << date.year << endl; 
    return 0;
}