#include<bits/stdc++.h>
using namespace std;

// It can optimized with space
int minimumCost(int *a, int n)
{
    if(n == 1) return 0;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        if(i == 1)
        {
            dp[i] = abs(a[i] - a[i-1]) + dp[0];
            continue;
        }
        dp[i] = min(abs(a[i] - a[i-1]) + dp[i-1], abs(a[i] - a[i-2]) + dp[i-2]);
    }
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<minimumCost(a, n);
}