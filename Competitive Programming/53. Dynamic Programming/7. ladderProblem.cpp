/*
Input: n, k
n -> No of steps
k -> maxmimum jump of K at each step

Output: #ways to reach nth steps
*/
#include<bits/stdc++.h>
using namespace std;

// Time -> Mat Pucho O(k^N) && Space -> O(N) for Stack
int noOfWays(int n, int k)
{
    if(n == 0)
    {
        return 1;
    }
    int ans = 0;
    for(int i=1; i<=k; i++)
    {
        if(n - i >= 0)
            ans += noOfWays(n-i, k);
    }
    return  ans;
}

// Time -> O(NK) && Space -> S(2*N)
int noOfWaysTopDown(int n, int k, int *dp)
{
    if(n == 0)
    {
        return 1; 
    }
    int ans = 0;
    if(dp[n]!=0) return dp[n];
    for(int i=1; i<=k; i++)
    {
        if(n - i >= 0)
            ans += noOfWaysTopDown(n-i, k, dp);
    }
    return dp[n] = ans;
}

// Time -> O(NK) && Space -> S(N)
int noOfWaysDownUp(int n, int k)
{
    int dp[n+1] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++)
    {
        int ans = 0;
        for(int j=1; j<=k; j++)
        {
            if(i-j >=0)
                ans += dp[i-j];
        }
        dp[i] =  ans;
    }
    return dp[n];
}

//By using sliding window 
// Time -> O(N) && Space -> S(N)
int noOfWaysDownUpOptimized(int n, int k)
{
    int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=k; i++)  
    {
        dp[i] = 2*dp[i-1]; 
    }
    for(int i=k+1; i<=n; i++)
    {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n+1] = {0}; 
    cout<<noOfWays(n, k)<<endl;
    cout<<noOfWaysDownUp(n, k)<<endl;
    cout<<noOfWaysDownUpOptimized(n, k)<<endl;
    cout<<noOfWaysTopDown(n, k, arr)<<endl;
    return 0;
}