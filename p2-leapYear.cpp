#include<iostream> 
using namespace std;

int getYear()
{
    int n;
    cout << "Enter Year: ";
    cin >> n;
    return n; 
}

string checkLeapYear(int num)
{
    if(num % 400 == 0)
      return "Leap Year";
    else if((num % 4 == 0) && (num % 100 != 0))
       return "Leap Year";
    else
        return "NOt Leap Year";
}

int main()
{
   int n = getYear();
   cout << checkLeapYear(n) << endl;
    return 0;
}