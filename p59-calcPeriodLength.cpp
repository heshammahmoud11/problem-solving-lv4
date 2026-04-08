#include<iostream>
using namespace std;


struct stDate
{
    short day;
    short month;
    short year;
};

struct stPeriod
{
    stDate startDate;
    stDate endDate;
}; 

short readDay()
{
    short n;
    cout << "Enter a Day: ";
    cin >> n;
    return n;
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
stDate readFullDate()
{
    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
}

stPeriod readPeriod()
{
    stPeriod  period;
    cout << "Enter Start Date: \n";
    period.startDate = readFullDate();
    cout << "\nEnter End Date: \n";
    period.endDate = readFullDate();
    
    return period;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getMonthDays(short month, short year)
{
    if(month < 1 || month > 12) return  0;
    short monArr[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monArr[month];
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
    }else 
    {
        date.day = 1;
        date.month = 1;
        date.year++;
    }

    return date;
}

bool isDate1_before_Date2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true 
         : (date1.year > date2.year) ? false
         : (date1.month < date2.month) ? true
         : (date1.month > date2.month) ? false
         : (date1.day < date2.day); 
}

bool isDate1_after_Date2(stDate date1, stDate date2)
{
    return (date1.year > date2.year) ? true
         : (date1.year < date2.year) ? false
         : (date1.month > date2.month) ? true
         : (date1.month < date2.month) ? false
         : (date1.day > date2.day);
}

short getDifference_N_Days(stDate strtDate , stDate endDate, bool includeEnd = false)
{
    short cnt = 0;
    while(isDate1_before_Date2(strtDate, endDate)) 
    {
        strtDate = increaseDate_by_1Day(strtDate);
        cnt++;
    }
    return includeEnd ? ++cnt : cnt; 
}

int clacPeriodLength_N_Days(stPeriod period, bool includeEnd = false)
{
    return getDifference_N_Days(period.startDate, period.endDate, includeEnd);
}

int main()
{
    cout << "Enter Period 1\n";
    stPeriod period = readPeriod();
    cout << "\n Ente Date to Check? \n";
    stDate checkDate = readFullDate();

    cout << "The Length of Period is: " <<  clacPeriodLength_N_Days(period) << endl;
    cout << "\nThe Length of Period is (Included End Day): " <<  clacPeriodLength_N_Days(period, true) << endl;
    return 0;
}