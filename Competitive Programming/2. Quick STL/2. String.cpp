#include<iostream>
#include<string.h>
using namespace std;

int main()
{

    // string s0;
    // string s1("Hello");
    // string s2 = "Hello!";
    // string s3(s2);
    // string s4 = s3;
    // char a[] = {'a', 'b', 'c', 'd', '\0'};
    // string s5(a);
    // cout<<s0<<endl;
    // cout<<s1<<endl;
    // cout<<s2<<endl;
    // cout<<s3<<endl;
    // cout<<s4<<endl;
    // cout<<s5<<endl;
    // cout<<s0.empty()<<endl;
    // s0.append("I love Competitve Programming");
    // cout<<s0<<endl;
    // s0 = s0 + " and Python as well!";
    // cout<<s0<<endl;
    // s0.clear();
    // cout<<s0.size()<<endl;
    // cout<<s0.length()<<endl;

    // s0 = "Apple";
    // s1 = "Mango";
    // cout<<s0.compare(s1)<<endl; //return and integer == 0, >= 0 or < 0

    // s0 > s1;
    // s1 > s0;

    // string s = "I want to have Apple Juice";
    
    // int idx = s.find("Apple");  //If not found that will give error
    // cout<<idx<<endl;

    // s.erase(idx, 5);
    // cout<<s<<endl;

    // for(auto it = s.begin(); it!=s.end(); it++)
    // {
    //     cout<<*it<<" ";
    // }
    // for(auto i : s)
    // {
    //     cout<<i;
    // }
    // cout<<endl;
    // cout<<sizeof(int)<<endl;

    // <string.h>
    //char* strtok(s, " ");
    // char *ptr = strtok(s, " ");
    char str[100] = "Today is a   rainy day";
    char *ptr = strtok(str, " ");
    cout<<ptr<<endl;
    while(ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        cout<<ptr<<endl;
    }
    return 0;
}