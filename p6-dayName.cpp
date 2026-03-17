#include<iostream> 
using namespace std;

short getYear()
{
    short year;
    cout << "Please Enter the Year: ";
    cin >> year;
    return year;
}
short getMonth()
{
    short month;
    cout << "Please Enter the Month: ";
    cin >> month;
    return month;
}
short getDay()
{
    short day;
    cout << "Please Enter the Day: ";
    cin >> day;
    return day;
}

void getDate(int day, int month, int year)
{
    string dayArr[7] = {"sunday", "monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday"}; 
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + (y/4) - (y/100) + (y/400) + ( (31 * m) / 12 ) ) % 7;




    cout << "\nDate : " << day << " / " << month << " / " << year << endl; 
    cout << "Day Order: " << d << endl;
    cout << "Day Name: " << dayArr[d] << endl;


}


int main()
{
    int year = getYear();
    int month = getMonth(); 
    int day = getDay();

    getDate(day, month, year);

    return 0; 
}