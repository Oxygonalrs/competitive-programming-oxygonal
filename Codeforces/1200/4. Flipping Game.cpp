#include<iostream>
#include<algorithm>
#include<climits>
#include<limits>
using namespace std;

// https://codeforces.com/problemset/problem/327/A

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int dp[n+1][n+1]; // 1-Base indexing
    int maximum = 0;
    for(int i=0; i<n; i++)
    {
        int count = 0;
        for(int j=i; j<n; j++)
        {
            if(a[j] == 1)
            {
                count++;
            }
            dp[i][j] = count;
            maximum = max(count, maximum);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int count = 0;
            for(int k=i; k<=j; k++)
            {
                if(1-a[k] == 1)
                {
                    count++;
                }
            }
            if(i == 0 && j== n-1)
            {
                ans = max(ans, count);
            }
            else if(i == 0 && j != n-1)
            {
                ans = max(ans, count + dp[j+1][n-1]);
            }
            else if(i != 0 && j == n-1)
            {
                ans = max(ans, count + dp[0][i-1]);
            }
            else{
                ans = max(ans, count + dp[j+1][n-1] + dp[0][i-1]);
            }
        }
    }
    cout<<ans<<endl;
    // cout<<max(maximum, ans)<<endl;
}