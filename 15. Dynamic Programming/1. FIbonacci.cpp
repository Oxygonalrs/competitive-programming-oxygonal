#include<iostream>
using namespace std;

//By using Recursion
int fib(int n)
{ 
    if(n == 0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}

//By Using DP
int Fib(int n, int *arr)
{
    if(n == 0 || n==1 )
        return n;
    if(arr[n] > 0) return arr[n];
    int output = Fib(n-1, arr) + Fib(n-2, arr);
    arr[n] = output;
    return output;
}

int FibI(int n)
{
    int arr[n+1] = {0};
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++)
    {
        arr[i] = arr[i-1] + arr[i - 2];
    }
    return arr[n];
}

int main()
{
    int n;
    cin>>n;
    int a[n+1] = {0};
    // cout<<fib(n)<<endl;
    cout<<Fib(n, a)<<endl;
    cout<<FibI(n)<<endl;
    return 0;
}