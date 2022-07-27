#include<iostream>
#include<climits>
using namespace std;

int maxProfit(int* price, int n)
{
    if(n <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++)
    {
        int cut = i+1;
        ans = max(ans, price[i] + maxProfit(price, n-cut));
    }
    return ans;
}

int maxProfitTopDown(int* price, int n, int* dp)
{
    if(n <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    if(dp[n]!= 0) return dp[n];
    for(int i=0; i<n; i++)
    {
        int cut = i+1;
        ans = max(ans, price[i] + maxProfitTopDown(price, n-cut, dp));
    }
    return dp[n] =ans;
}

int maxProfitDownUp(int* price, int n)
{
    int dp[n+1] = {0};
    dp[0] = 0;
    for(int len = 1; len<=n; len++)
    {
        int ans = INT_MIN;
        for(int i=0; i<len; i++)
        {
            int cut = i+1;
            int current_ans = price[i] + dp[len - cut];
            ans = max(current_ans, ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main()
{
    int price [] = {3, 5, 8, 9, 10, 17, 17, 20};
    int k = sizeof(price)/sizeof(int);
    int dp[k+1] = {0};
    cout<<maxProfit(price, k)<<endl;
    cout<<maxProfitDownUp(price, k)<<endl;
    cout<<maxProfitTopDown(price, k, dp)<<endl;
    
}