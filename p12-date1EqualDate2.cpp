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

bool Date1_Equal_Date2(stDate date1, stDate date2)
{
    return (date1.year == date2.year) ? ( (date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false  )  : false ;
}

int main()
{
    stDate date1 = readFullData();
    stDate date2 = readFullData();

    if(Date1_Equal_Date2(date1, date2)) cout << "Both of Dates Equals\n";
    else cout << "Not Equals\n";

    return 0;
}


/* 


*/