#include<iostream> 
using namespace std; 

struct stDate
{
    short day;
    short month;
    short year;
};
short getDay()
{
    short d;
    cout << "Enter a Day: ";
    cin >> d;
    return d;
}
short getMonth()
{
    short m;
    cout << "Enter a Month: ";
    cin >> m;
    return m;
}

short getYear()
{
    short y;
    cout << "Enter a Year: ";
    cin >> y;
    return y;
}

short addNewDays()
{
    short add;
    cout << "Enter a Number of Days You want to Add: ";
    cin >> add;
    return add;
}

stDate readFullDate()
{
    stDate date;
    date.day = getDay();
    date.month = getMonth();
    date.year = getYear();

    return date;
}
bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); 
}

short getMonthDays(short month, short year)
{
    if(month < 1 || month > 12) return 0; 
    short monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monthDays[month];
}

short NumberofDays_From_Begining(short day, short month, short year)
{
    short sumDays = 0; 
    for(int i = 1; i <= (month - 1); i++)
    {
        sumDays += getMonthDays(i, year);
    }

    return sumDays + day;
}

stDate addNewDays(short day, stDate date)
{
    short remainDays = day + NumberofDays_From_Begining(date.month, date.month, date.year);
    short monthDays = 0;
    date.month = 1;

    while(true)
    {
        monthDays = getMonthDays(date.month, date.year);

        if(remainDays > monthDays)
        {
            remainDays -= monthDays;
            date.month++;
            if(date.month > 12) 
            {
                date.month = 1;
                date.year++;
            }
        }else 
        {
            date.day = remainDays;
            break;
        }
    }

    return date;
}


int main()
{
    stDate date = readFullDate();
    short addDays = addNewDays();

    date = addNewDays(addDays, date); 

    cout << "Day After Adding Days [ " << addDays << " ] days is: ";
    cout <<  date.day << " / " << date.month << " / " << date.year << endl;


    return 0;
}
