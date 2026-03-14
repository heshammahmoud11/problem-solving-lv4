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
    if(month < 1 || month > 12)  return 0;

    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (checkLeapYear(year) ? 29 : 28 ) : days[month];

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