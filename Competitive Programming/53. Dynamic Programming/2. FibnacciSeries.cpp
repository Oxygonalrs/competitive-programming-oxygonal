#include<iostream>
using namespace std;

int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    int ans;
    ans = fib(n-1) + fib(n-2);
    return ans;
}

int fibRecursive(int n, int * dp)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }
    int ans;
    ans = fibRecursive(n-1, dp) + fibRecursive(n-2,dp);
    dp[n] = ans;
    return dp[n];
}

int fibBottomUp(int n)
{
    if(n ==0 || n==1)
    {
        return n;
    }
    int dp[n+1] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fibAdvancedBottomUp(int n)
{
    if(n ==0 || n==1)
    {
        return n;
    }
    int dp[n+1] = {0};
    int  lastSecondIndex = 0;
    int lastFirstIndex = 1;
    int c;
    for(int i=2; i<=n; i++)
    {
        c = lastFirstIndex + lastSecondIndex;
        lastSecondIndex = lastFirstIndex;
        lastFirstIndex = c; 
    }
    return c;
}



int main()
{
    int n;
    cin>>n;
    int dp[100+1] = {0};
    cout<<fibBottomUp(n)<<endl;
    cout<<fibAdvancedBottomUp(n)<<endl;
    cout<<fibRecursive(n, dp)<<endl;
    // cout<<fib(n)<<endl;
}