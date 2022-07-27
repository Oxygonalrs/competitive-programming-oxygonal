#include<iostream>
using namespace std;
#define PI 22/7
//When it will compile means before compiling it will replace all PI with 22/7

//It will take some memory and time of access 
//double pi = 3.14;


//It will copy function body at run time where this function called
//It only copy 1-3 line of code and not more than 3
inline int max(int a, int b)
{
    return (a>b) ? a : b;
}
 

//Default argument 
int sum(int a, int b=10)
{
    return a+b;
}

int main()
{
    cout<<PI*7*7<<endl;

    int a,b;
    cin>>a>>b;

    // int c = (a>b) ? a : b;
    int c = max(a,b);
    cout<<c<<endl;

    cout<<sum(5,12)<<endl;
    cout<<sum(5)<<endl;
    return 0;
}