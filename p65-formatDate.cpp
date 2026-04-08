#include<iostream>
#include<vector>
using namespace std;

string dateString(string mssg)
{
    string date;
    cout << mssg;
    getline(cin >> ws, date); 
    return date;
}

struct stDate
{
    short day;
    short month;
    short year;
}; 

vector<string> splitString(string str, string delim = "/")
{
    short pos = 0; 
    string sword = "";

    vector<string> vString;

    // check if string is valid or not
    while((pos = str.find(delim)) != string::npos)
    {
        sword = str.substr(0, pos);
        if(sword != "")
        {
            vString.push_back(sword);   
        }
        str.erase(0, pos + delim.length());
    } 

    if(str != "") 
       vString.push_back(str);

    return vString;
}

stDate string2Struct(string str, string delim = "/")
{
    vector<string> vString = splitString(str);
    stDate date;

    date.day = stoi(vString[0]);
    date.month = stoi(vString[1]);
    date.year = stoi(vString[2]);

    return date;
}

string replaceWord(string str, string replaceFrom, string replaceTo)
{
    short pos = str.find(replaceFrom);
    while(pos != string::npos)
    {
        str = str.replace(pos, replaceFrom.length(), replaceTo);
        pos = str.find(replaceFrom); 
    }
    return str; 
}

string formatDate(stDate date, string dateFormat = "dd/mm/yyyy")
{
   string dateStr = "";

   dateStr = replaceWord(dateFormat, "dd", to_string(date.day));
   dateStr = replaceWord(dateStr, "mm", to_string(date.month));
   dateStr = replaceWord(dateStr, "yyyy", to_string(date.year)); 

   return dateStr;
}

int main()
{
    string readStr = dateString("Enter a Data as a String: ");
    stDate date = string2Struct(readStr);


     cout << "\n" << formatDate(date) << endl;
     cout << "\n" << formatDate(date, "yyyy/dd/mm") << endl;
     cout << "\n" << formatDate(date, "mm/dd/yyyy") << endl;
     cout << "\n" << formatDate(date, "mm-dd-yyyy") << endl;
     cout << "\n" << formatDate(date, "dd-mm-yyyy") << endl;
     cout << "\n" << formatDate(date, "Day:dd, Month:mm, Year: yyyy") << endl;

    
    return 0; 
}