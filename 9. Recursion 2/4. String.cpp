#include<iostream>
using namespace std;

int main()
{
    string s = "abc";
    string *sp = new string;
    *sp = "def";
    cout<<s<<endl;
    cout<<*sp<<endl;
    cout<<sp<<endl;

    s = "";
    // cin>>s;
    getline(cin, s);
    cout<<s<<endl;
    cout<<s.size()<<endl;
    cout<<s.length()<<endl;
    // substr(starting Index, length)
    cout<<s.substr(3,5)<<endl;
    // return first finding index
    cout<<s.find("n")<<endl;
}