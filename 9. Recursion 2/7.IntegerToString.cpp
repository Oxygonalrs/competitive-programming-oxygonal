#include<iostream>
using namespace std;

int stringToInteger(int ans, string str)
{
    // if(str.length() == 1)
    // {
    //     int currentNumber = str[0] - '0';
    //     return currentNumber;
    // }
    if(str.length() == 0)
    {
        return 0;
    }
    int currentNumber = str[0] - '0';
    int smallNumber = stringToInteger(ans, str.substr(1));
    return currentNumber*10 + smallNumber;
}

int main()
{
    string str;
    cin>>str;
    int number = stringToInteger(0,str);
    cout<<number<<endl;
}