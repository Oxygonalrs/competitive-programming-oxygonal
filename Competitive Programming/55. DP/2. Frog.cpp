#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

// It can optimized with space
int minimumCost(int *a, int n, int k)
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
        int count = k;
        int ans = INT_MAX;
        for(int j=i-1; (j>=0 && count > 0); j--)
        {
            ans = min(ans, abs(a[i] - a[j]) + dp[j]);
            count--;
        }
        dp[i] = ans;
        // dp[i] = min(abs(a[i] - a[i-1]) + dp[i-1], abs(a[i] - a[i-2]) + dp[i-2]);
    }
    return dp[n-1];
}

int main()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<minimumCost(a, n, k);
}