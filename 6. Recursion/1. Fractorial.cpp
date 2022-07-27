#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    int samlloutput = n*fact(n-1);
    return samlloutput;
}

int main()
{
    int n;
    cin>>n;
    int output = fact(n);
    cout<<output<<endl;
    return 0;
}