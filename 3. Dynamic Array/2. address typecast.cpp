#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=65;
    char c = i;
    char ch = 'A';
    int *p = &i;
    // char *pc = (char *)&i;
    char *pc = (char *)p;
    // cout<<c<<endl;
    // cout<<ch<<endl;
    // cout<<'A'<<endl;
    cout<<*p<<endl;
    cout<<*pc<<endl;
    cout<<*(pc+1)<<endl;
    cout<<*(pc+2)<<endl;
    cout<<*(pc+3)<<endl;
    
    cout<<p<<endl;
    cout<<pc<<endl;
    return 0;
}