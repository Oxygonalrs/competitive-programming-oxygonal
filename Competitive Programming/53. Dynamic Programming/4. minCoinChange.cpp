#include<bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
//I can use binary search because coins are sorted, so i can lower bound function

int minChange(int n)
{
    if(n == 1 || n == 0)
    {
        return n;
    }
    int temp = INT_MAX;
    for(int i=0; i<10; i++)
    {
        if(n >= coins[i])
            temp = min(temp, minChange(n - coins[i]));
    }
    return temp + 1;
}

int minChangeTopDown(int n, int* dp)
{
    if(n == 1 || n == 0)
    {
        return n;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }
    int temp = INT_MAX;
    for(int i=0; i<10; i++)
    {
        if(n >= coins[i])
            temp = min(temp, minChangeTopDown(n - coins[i], dp));
    }
    return dp[n] = temp + 1;
}

int minChangeBottomUp(int n)
{
    if(n == 1 || n == 0)
    {
        return n;
    }
    int dp[1001] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {   int temp = INT_MAX;
        for(int j=0; j<10; j++)
        {
            if(i >= coins[j])
                temp = min(temp, dp[i - coins[j]]);
        }
        dp[i] = temp + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int dp[10001] = {0};
    cout<<minChangeTopDown(n, dp)<<endl;
    cout<<minChangeBottomUp(n)<<endl;
    // cout<<minChange(n)<<endl;
}