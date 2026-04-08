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
short isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
short getMonthDays(short month, short year)
{
    if(month < 1 || month > 12) return 0;
    short monthArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monthArr[month];
}

bool isData1_before_date2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true
         : (date1.year > date2.year) ? false
         : (date1.month < date2.month) ? true
         : (date1.month > date2.month) ? false
         : (date1.day < date2.day);
         
        // Other Solution
        //     return (date1.year < date2.year) ? true
        //  : (date1.year == date2.year) ? (date1.month < date2.month) ? true
        //  : (date1.month == date2.month) ? (date1.day < date2.day) : false : false;
}

stDate increaseDate_by_OneDay(stDate date)
{
    if(date.day < getMonthDays(date.month, date.year))
    {
        date.day++;
    }else if(date.month < 12)
    {
        date.day = 1;
        date.month++;
    }else{
        date.day = 1;
        date.month = 1;
        date.year++;
    }

    return date;
}

stDate readFullDate()
{
    stDate date;
    date.day = getDay();
    date.month = getMonth();
    date.year = getYear();
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
    string weekDays[7] {"Sun", "Mon","Tue", "Wed", "Thu", "Fri", "Sat"};
    return weekDays[dayOrder];
}
bool isWeekEnd(stDate date)
{
    short dayIndex = dayOrder_N_Week(date.day, date.month, date.year);
    return (dayIndex == 5 || dayIndex == 6); 
}

bool isBusinessDay(stDate date)
{
    return !isWeekEnd(date);
}


short calcRealVacations(stDate date1, stDate date2)
{
    short cnt = 0;
    while(isData1_before_date2(date1, date2))
    {
        if(isBusinessDay(date1))
        {
            cnt++;
        }
        date1 = increaseDate_by_OneDay(date1);
    }
    return cnt;
}
int main()
{
    cout << "Vecation Starts At: \n";
    stDate date1 = readFullDate();
    cout << "\n";
    cout << "Vavation Ends At: \n";
    stDate date2 = readFullDate();
    
    cout << "\nVacation From: " << dayName(dayOrder_N_Week(date1.day, date1.month, date1.year)) << " , " << date1.day << " / " << date1.month << " / " << date1.year << endl;
    cout << "Vacation To: " << dayName(dayOrder_N_Week(date2.day, date2.month, date2.year)) << " , " << date2.day << " / " << date2.month << " / " << date2.year << endl;

    cout << "\n Actual Vacation Days is: " << calcRealVacations(date1, date2) << endl;
    return 0;
}


/* 

bool isData1_before_date2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true
         : (date1.year == date2.year) ? (date1.month < date2.month) ? true
         : (date1.month == date2.month) ? (date1.day < date2.day) : false : false;
}
*/