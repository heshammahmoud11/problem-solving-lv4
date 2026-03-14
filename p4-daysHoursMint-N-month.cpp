#include<iostream> 
using namespace std;

short getYear()
{
    short n;
    cout << "Enter a Year: ";
    cin >> n;
    return n; 
}
short getMonth()
{
    short n;
    cout << "Enter a Month: ";
    cin >> n;
    return n; 
}

bool checkLeapYear(int year)
{
    return  (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) ; 
}

short checkMonth(int month, int year)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==10 || month == 12)
        return 31; 

    else if(month == 2)
    {
        if(checkLeapYear(year)) return 29;
        else return 28;
    }
    else 
        return 30;
    
}

int getHours(int month, int year)
{
    return checkMonth(month, year) * 24;
}
int getMinutes(int month, int year)
{
    return  getHours(month, year) * 60;
}
int getSeconds(int month, int year)
{
    return  getMinutes(month, year) * 60;
}

void printRes(int month, int year)
{
    cout << "Number of Days in Month [ " << month << " ] is : " << checkMonth(month, year) << endl;
    cout << "Number of Hours in Month [ " << month << " ] is : " << getHours(month, year) << endl;
    cout << "Number of Minutes in Month [ " << month << " ] is : " << getMinutes(month, year) << endl;
    cout << "Number of Seconds in Month [ " << month << " ] is : " << getSeconds(month, year) << endl;
}

int main()
{
   int year = getYear();
   int month = getMonth();
   printRes(month, year);
    return 0;
}