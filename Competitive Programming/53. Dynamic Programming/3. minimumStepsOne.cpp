#include<bits/stdc++.h>
using namespace std;

int minimumSteps(int n)
{
    if(n == 1 || n==0)
    {
        return 0;
    }
    int ans = INT_MAX;
    if(n%3 == 0)
    {
        ans = minimumSteps(n/3);
    }
    if(n%2 == 0)
    {
        ans = min(ans, minimumSteps(n/2));
    }
    ans = min(ans, minimumSteps(n-1));
    return 1 + ans;
}

int minimumStepsTopDown(int n, int* dp)
{
    if(n == 1 || n==0)
    {
        return 0;
    }
    if(dp[n] !=0)
    {
        return dp[n];
    }
    int ans = INT_MAX;
    if(n%3 == 0)
    {
        ans = minimumStepsTopDown(n/3,dp);
    }
    if(n%2 == 0)
    {
        ans = min(ans, minimumStepsTopDown(n/2, dp));
    }
    ans = min(ans, minimumStepsTopDown(n-1, dp));
    return dp[n] = 1 + ans;
}

int minimumStepsDownUp(int n)
{
    if(n == 1 || n==0)
    {
        return 0;
    }
    int dp[1000] = {0};
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        int ans = dp[i-1];
        if(i%2 == 0)
        {
            ans = min(ans, dp[i/2]);
        }
        if(i%3 == 0)
        {
            ans = min(ans, dp[i/3]);
        }
        dp[i] = 1 + ans;
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int dp[1000] = {0};
    cout<<minimumSteps(n)<<endl;
    cout<<minimumStepsTopDown(n, dp)<<endl;
    cout<<minimumStepsDownUp(n)<<endl;
    return 0;
}