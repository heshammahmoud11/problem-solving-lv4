#include<iostream> 
using namespace std;

int getYear()
{
    int n;
    cout << "Enter Year: ";
    cin >> n;
    return n; 
}

bool checkLeapYear(int num)
{
    return  (num % 400 == 0) || ((num % 4 == 0) && (num % 100 != 0)) ; 
}

short getDays(int num)
{   
    return checkLeapYear(num) ? 366 : 365 ;
    
}
int getHours(int num)
{
    return getDays(num) * 24;
}
int getMinutes(int num)
{
    return  getHours(num) * 60;
}
int getSeconds(int num)
{
    return  getMinutes(num) * 60;
}
void printRes(int num)
{
    cout << "Number of Days in Year [ " << num << " ] is : " << getDays(num) << endl;
    cout << "Number of Hours in Year [ " << num << " ] is : " << getHours(num) << endl;
    cout << "Number of Minutes in Year [ " << num << " ] is : " << getMinutes(num) << endl;
    cout << "Number of Seconds in Year [ " << num << " ] is : " << getSeconds(num) << endl;
}

int main()
{
   int n = getYear();
   printRes(n);
    return 0;
}