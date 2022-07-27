#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

int numWays(int row, int col)
{
    if (dp[0][0] == -1)
        return 0;
    
    for(int j=0; j<col; j++)
    {
        if (dp[0][1] == -1)
        {
            break;
        }
        dp[0][j] = 1;
    }
    for(int j=0; j<row; j++)
    {
        if (dp[j][0] == -1)
        {
            break;
        }
        dp[j][0] = 1;
    }

    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            if(dp[i][j] == -1)
            {
                continue;
            }
            dp[i][j] = 0;
            
            if(dp[i][j-1]!=-1)
            {
                dp[i][j] = dp[i][j-1]%MOD;
            }
             if(dp[i - 1][j]!=-1)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            }
        }
        
    }
    if(dp[row-1][col-1] == -1)
    {
        return 0;
    }
    return dp[row - 1][col-1];
}

int main()
{
    int t;
    cin>>t;
    while(t)
    {

    }
}