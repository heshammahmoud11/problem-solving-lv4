#include<iostream>
#include<vector>
using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
}; 

string readDate()
{
    string str;
    cout << "Enter Date dd/mm/yyyy : ";
    getline(cin >> ws, str); 
    return str;
}

vector<string> splitString(string str, string delim = "/")
{
    vector<string> vString;

    short pos = 0;
    string sword = "";

    while((pos = str.find(delim)) != string::npos)
    {
        sword = str.substr(0, pos);
        if(sword != "")
        {
            vString.push_back(sword);
        }
        // this erase the previous word until postion, and move to next word
        str.erase(0, pos + delim.length());
    }

    //  this handle the last word after delim
    if(str != "") 
       vString.push_back(str);


    return vString;
}

stDate convertStr2Struct(string str)
{
    vector<string> stVector = splitString(str);
    stDate date;

    date.day = stoi(stVector[0]);
    date.month = stoi(stVector[1]);
    date.year = stoi(stVector[2]);

    return date;
}


string convertStruct2Str(stDate date)
{
   return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

int main()
{
    string date = readDate();

    stDate dateRes = convertStr2Struct(date);

    cout << "Day: " << dateRes.day << endl;
    cout << "Month: " << dateRes.month << endl;
    cout << "Year: " << dateRes.year << endl;
    cout << "\n----------------\n";

    cout << "You Enter : " << convertStruct2Str(dateRes) << endl;
    return 0;
}