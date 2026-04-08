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

    return (month == 2) ? (isLeap(year) ? 29 : 28 ) : monthArr[month];
}

short numberOfDays_From_BeginingYear(short day, short month, short year)
{
    short totalDays = 0;

    for(short i = 1; i <= (month - 1); i++)
    {
        totalDays += getMonthDays(i, year);
    }
    return totalDays + day;
}


short compare2Dates(stDate date1, stDate date2)
{
    short dateOne = numberOfDays_From_BeginingYear(date1.day, date1.month, date1.year);
    short dateTwo = numberOfDays_From_BeginingYear(date2.day, date2.month, date2.year);

    if(dateOne > dateTwo) 
       return dateOne - dateTwo;
    else 
       return dateTwo - dateOne;
}




int main()
{
    stDate date1 = readFullData();
    cout << "\n";
    stDate date2 = readFullData(); 
    
    cout << "The Diff Between 2 Dates is: " << compare2Dates(date1, date2) << " Days\n";
    cout << "The Diff Between 2 Dates is Includeing End Day : " << compare2Dates(date1, date2) + 1 << " Days\n";
}

