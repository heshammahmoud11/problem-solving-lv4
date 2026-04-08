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

stDate decreaseDate_by_1Day(stDate date)
{
    if(date.day > 1)
    {
        date.day--;
    }
    else if(date.month > 1)
    {
        date.month--;
        date.day = getMonthDays(date.month, date.year);
    }
    else
    {
        date.day = 31;
        date.month = 12;
        date.year--;
    }
    return date;
}

stDate decreaseDate_by_xDays(stDate date, short days)
{
    while(days--)
    {
        date = decreaseDate_by_1Day(date);
    }
    return date;
}

stDate decreaseDate_by_1Week(stDate date)
{
    for(short i = 1; i <= 7; i++)
    {
        date = decreaseDate_by_1Day(date);
    }
    return date;
}

stDate decreaseDate_by_xWeeks(stDate date, short weeks)
{
    while(weeks--)
    {
        date = decreaseDate_by_1Week(date);
    }
    return date;
}

stDate decreaseDate_by_1Month(stDate date)
{
    if(date.month == 1)
    {
        date.month = 12;
        date.year--;
    }else
    {
        date.month--;
    }

    short numOfDays  = getMonthDays(date.month, date.year);
    if(date.day > numOfDays)
    {
        date.day = numOfDays;
    }

    return date;

}
stDate decreaseDate_by_xMonth(stDate date, short month)
{
    for(short i = 1; i <= month; i++)
    {
        date = decreaseDate_by_1Month(date);
    }
    return date;
}
stDate decreaseDate_by_1Year(stDate date)
{
    date.year--;
    return date;
}
stDate decreaseDate_by_xYear(stDate date, short year)
{
    date.year -= year;
    return date;
}
stDate decreaseDate_by_1Decode(stDate date)
{
    date.year -= 10;
    return date;
}
stDate decreaseDate_by_XDecode(stDate date, short decode)
{
    date.year -=  decode * 10;
    return date;
}
stDate decreaseDate_by_1Century(stDate date)
{
    date.year -= 100;
    return date;
} 
stDate decreaseDate_by_Millinum(stDate date)
{
    date.year -= 1000;
    return date;
}



int main()
{
    stDate date1 = readFullDate();
    cout << "\n--------- After Decreasing --------------\n";

    date1 = decreaseDate_by_1Day(date1);
    cout << "01-Decrease 1 Day: " << date1.day << " / " << date1.month << " / " << date1.year << endl;

    date1 = decreaseDate_by_xDays(date1, 10);
    cout << "02-Decrease X Days: " << date1.day << " / " << date1.month << " / " << date1.year << endl;
    
    return 0;
}

