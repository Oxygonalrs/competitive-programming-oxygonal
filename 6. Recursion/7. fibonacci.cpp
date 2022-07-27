#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==1) return 1;
    if(n==0) return 0;
    int output = fib(n-1) + fib(n-2);
    return output;
}

int main()
{
    int n;
    cin>>n;
    int output = fib(n);
    cout<<output<<endl;
    return 0;
}