#include<iostream>
using namespace std;

int power(int n, int x)
{
    if(n==0)
    {
        return 1;
    }
    int smalloutput = power(n-1,x);
    int output = x*smalloutput;
    return output;
    
}

int main()
{
    int n,x;
    cin>>n>>x;
    int output = power(n,x);
    cout<<output<<endl;
    return 0;
}