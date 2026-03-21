#include<iostream>
#include<iomanip>
using namespace std; 

short getYear()
{
    short n;
    cout << "Please Enter a Year: "; 
    cin >> n;
    return n; 
}

short getMonth()
{
    short n; 
    cout << "Please Enter a Month: ";
    cin >> n;
    return n; 
}

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getMonthDays  (short month, short year)
{
    if (month < 1 || month > 12) return 0;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2)? (isLeapYear(year) ? 29 : 28) : days[month]; 
}

// this function give me the first day in the month

short getDayOrder(short day, short month, short year)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2; 

    short d =  (day + y + (y/4) - (y/100) + (y/400) + ( (31 * m) / 12 ) ) % 7;

    return d;

}

string getDayName(short day)
{
    string dayArr[7] = {"sunday", "monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday"}; 
    return dayArr[day];
}

string monthName(short month)
{
    string monthArr[13] {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Augs", "Sept", "Oct","Nov", "Dec"};
    return monthArr[month];
  
}
void printMonthCalendar(short month, short year)
{
    int monthDays = getMonthDays(month, year);

    short firstDay = getDayOrder(1, month, year);


    printf ( "\n_______________________%s________________________\n\n", monthName(month).c_str()); 

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // make all days before the first day empty spaces 
    int i = 0;
    for( i = 0; i < firstDay; i++)
    {
        printf("     "); 
    }

    for(int j = 1; j <= monthDays; j++)
    {
        printf("%5d", j);
        
        if(++i == 7) 
        {
            i = 0;
            printf("\n");
       }
    }
    cout << "\n_______________________________________________\n\n";
}

void printYearCalendar(short year)
{
    printf("______________________________\n");
    printf("\n\tCalender _ %d\n", year);
    printf("______________________________\n");
  for(int i = 1; i <= 12; i++)
  {
    printMonthCalendar(i, year);
  }
}

int main()
{
   short y = getYear();
   printYearCalendar(y); 

    return 0;
}