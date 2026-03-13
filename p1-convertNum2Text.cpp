#include<iostream> 
using namespace std;


long long getNumber()
{
    long long n; 
    cout << "Enter a Number: ";
    cin  >> n; 
    return n; 
}



string convertNumber2Text(long long num)
{
    string firstArr[] = {"", "one", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten","eleven",
                   "Tweleve", "Thirteen", "Fourteen", "Fivtenn", "Sixtenn", "Seventeen", "eigteen", "nineteen"};
    
    string teens[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};

    if(num == 0)
        return "";
    
    
    if(num >= 1 && num <= 19)
        return firstArr[num];
    

    if(num >= 20 && num <= 99)
        return teens[num/10] + " " + convertNumber2Text(num % 10);
    

    if(num >= 100 && num <= 999)
        return convertNumber2Text(num/100) + " Hundred " + convertNumber2Text(num % 100);
    

    if(num >= 1000 && num <= 999999)
        return convertNumber2Text(num / 1000) + " Thousand " + convertNumber2Text(num % 1000);
    

    if(num >= 1e6 && num <= 1e9 - 1)
        return convertNumber2Text(num / (1e6)) + " Million " + convertNumber2Text(num % (1000 * 1000));
    

    if(num >= 1e9)
        return convertNumber2Text(num / (1e9)) + " Billion " + convertNumber2Text(num % (1000 * 1000 * 1000));
    
      
    return ""; 
}



int main()
{
    long long num = getNumber();
    cout << convertNumber2Text(num) << endl; 


    return 0;
}