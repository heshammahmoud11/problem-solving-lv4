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

enum enCompareDates {before = -1, equal = 0, after = 1}; 

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
    cout << "\nEnter Start Date: \n";
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

bool isDate1_Equal_Date2(stDate date1, stDate date2)
{
    return (!isDate1_after_Date2(date1, date2) && !isDate1_before_Date2(date1, date2));
}

enCompareDates compareDates(stDate startDate, stDate endDate)
{
    if(isDate1_after_Date2(startDate, endDate))
       return enCompareDates::after;

    if(isDate1_before_Date2(startDate, endDate))
       return enCompareDates::before;

    return enCompareDates::equal;
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
        date.year++; 
    }
    
    return date;
}

short getDifference_N_Dates(stDate date1, stDate date2, bool includEnd = false)
{
    int dayCnt = 0;

    while(isDate1_before_Date2(date1, date2))
    {
        dayCnt++; 
        date1 = increaseDate_by_1Day(date1);
    }
    return includEnd ? ++dayCnt : dayCnt ;
}

short calcPeriod_length(stPeriod period, bool includEnd = false)
{
    return getDifference_N_Dates(period.startDate, period.endDate, includEnd);
}

enCompareDates comapreDates(stDate date1, stDate date2)
{
    if(isDate1_after_Date2(date1, date2))
       return enCompareDates::after;
    else if(isDate1_before_Date2(date1, date2))
       return enCompareDates::before;
    else 
       return enCompareDates::equal;
}

bool isDate_N_Period(stPeriod period, stDate date)
{
    return !(compareDates(date, period.startDate) == enCompareDates::before || 
            compareDates(date, period.endDate) == enCompareDates::after); 
}

bool isOverlaped(stPeriod period1, stPeriod period2)
{
   if(compareDates(period2.endDate, period1.startDate) == enCompareDates::before 
    || compareDates(period2.startDate, period1.endDate) == enCompareDates::after)
        return false;
    else
        return true;
     
}

short calcOverlapDays_N_Periods(stPeriod period1, stPeriod period2)
{
    int periodOne_Length = calcPeriod_length(period1, true);
    int periodTwo_Length = calcPeriod_length(period2, true);
    int overlapDays = 0;


    if(!isOverlaped(period1, period2))
       return false;
    
    
    if(periodOne_Length < periodTwo_Length)
    {
        while(isDate1_before_Date2(period1.startDate, period1.endDate))
        {
            if(isDate_N_Period(period2, period1.startDate))
                 overlapDays++;

            period1.startDate = increaseDate_by_1Day(period1.startDate);
        }
    }else 
    {
        while(isDate1_before_Date2(period2.startDate, period2.endDate))
        {
            if(isDate_N_Period(period1, period2.startDate))
                 overlapDays++;
                 
            period2.startDate = increaseDate_by_1Day(period2.startDate);
        }
    }
    
    return overlapDays; 
       
}

 int main()
{
    cout << "Enter Period 1\n";
    stPeriod period1 = readPeriod();
    cout << "\nEnter Period 2\n";
    stPeriod period2 = readPeriod();

    cout << "The Overlap Days : " << calcOverlapDays_N_Periods(period1, period2) << endl;
}