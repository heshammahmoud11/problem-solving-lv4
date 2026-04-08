#include<iostream>
using namespace std;


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



struct stDate
{
    short day;
    short month;
    short year;
};

stDate readFullDate()
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
    short monthArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (isLeap(year) ? 29 : 28) : monthArr[month];
}

stDate increaseDate_by_1Day(stDate date )
{
    if(date.day < getMonthDays(date.month, date.year))
    {
        date.day++;
    }else if(date.month < 12)
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



stDate increaseDate_by_xDay(stDate date, short xDay)
{
    while(xDay--)
    {
        date = increaseDate_by_1Day(date);
    }   
    return date;
}

stDate increaseDate_by_1Week(stDate date)
{
    for(short i = 1; i <= 7; i++)
    {
        date = increaseDate_by_1Day(date);
    }
    return date;
}

stDate increaseDate_by_xWeek(stDate date, short week)
{
    while(week--)
    {
        date = increaseDate_by_1Week(date);
    }
    return date;
}

stDate increasedDate_by_1month(stDate date)
{
   if(date.month == 12)
   {
     date.month = 1;
     date.year++;
   }else
   {
     date.month++;
   }

   short numOfDays_N_Month = getMonthDays(date.month, date.year);

   if(date.day > numOfDays_N_Month)
   {
      date.day = numOfDays_N_Month;
   }

   return date;
}  

stDate increaseDate_by_xMonth(stDate date, short month)
{
    while(month--)
    {
        date = increasedDate_by_1month(date);
    }
    return date;
}

stDate increaseDate_by_1Year(stDate date)
{
    date.year++;
    return date;
}
stDate increaseDate_by_xYear(stDate date, short year)
{
    while(year--)
    {
        date = increaseDate_by_1Year(date);
    }
    return date;
}
stDate increaseDate_by_xYearFaster(stDate date, short year)
{
    date.year += year;
    return date;
}
stDate increaseDate_by_1Decode(stDate date)
{
    date.year += 10;
    return date;
}
stDate increaseDate_by_xDecode(stDate date, short decode)
{
    while(decode--)
    {
        date = increaseDate_by_1Decode(date);
    }
    return date;
}
stDate increaseDate_by_xDecodeFaster(stDate date, short decode)
{
    date.year += decode * 10;
    return date;
}
stDate increaseDate_by_1Century(stDate date)
{
    date.year += 100;
    return date;
}
stDate increaseDate_by_Millinum(stDate date)
{
    date.year += 1000;
    return date;
}
int main()
{
    stDate date1 = readFullDate();
    cout << "\n------------ Date After ----------\n";

    date1 = increaseDate_by_1Day(date1);
    cout << "01-Adding One Day is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xDay(date1, 10);
    cout << "02-Adding X Days is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_1Week(date1);
    cout << "03-Adding 1 Week is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xWeek(date1, 12);
    cout << "04-Adding x Week is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increasedDate_by_1month(date1);
    cout << "05-Adding One Month is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xMonth(date1, 3);
    cout << "06-Adding X Month is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_1Year(date1);
    cout << "07-Adding 1 Year is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xYear(date1, 3);
    cout << "08-Adding X Year is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xYearFaster(date1, 3);
    cout << "09-Adding X Year Faster is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_1Decode(date1);
    cout << "10-Adding 1 Decode is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xDecode(date1, 3);
    cout << "11-Adding X Decode is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_xDecodeFaster(date1, 3);
    cout << "12-Adding X Decode Faster is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_1Century(date1);
    cout << "13-Adding 1 Century is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = increaseDate_by_Millinum(date1);
    cout << "14-Adding 1 Millinum is: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    return 0;
}

/* 
 
stDate increaseDate_by_oneMonth(stDate date)
{ 
   if(date.month == 12)
   {
      date.month = 1;
      date.year++;
   }else
   {
        date.month++;
   }

   short numOfDays_N_Month = getMonthDays(date.month, date.year);
   if(date.day > numOfDays_N_Month)
   {
      date.day = numOfDays_N_Month;
   }

    return date;
}
*/

