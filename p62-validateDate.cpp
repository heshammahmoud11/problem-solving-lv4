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

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getMonthDays(short month, short year) 
{
    if(month < 1 || month > 12) return 0;
    short monArray[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monArray[month]; 
}

bool isValidDate(stDate date)
{
    if(date.month < 1 || date.month > 12)
       return false;

    if(date.day < 1 || date.day > getMonthDays(date.month, date.year))
       return false; 
    
    return true;
}

int main()
{
    cout << "\nEnter Date : \n"; 
    stDate date = readFullDate();
    
    if(isValidDate(date))
       cout << "Yes, Date is Validate\n";
    else
       cout << "NO, dAte is not validate\n";
    return 0;
}