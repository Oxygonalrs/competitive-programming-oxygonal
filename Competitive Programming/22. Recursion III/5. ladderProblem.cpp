#include<iostream>
using namespace std;

/*
    f(n) = f(n-1) + f(n-2) + f(n-3);
    if(i<0)
    {
        return 1;
    }
*/
int f(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0) return 1;
    return f(n-1) + f(n-2) + f(n-3);
}

int main()
{
    int n;
    n = 4;
    cout<<f(n);
}