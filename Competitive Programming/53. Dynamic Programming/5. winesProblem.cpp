#include<bits/stdc++.h>
using namespace std;

int wines[] = {2, 3, 5, 1, 4};

// Recursion
int winesProblem(int x, int y, int i)
{
    if(x > y)
    {
        return 0;
    }
    int ans = i*wines[x] + winesProblem(x+1, y, i+1);
    int ans2 = i*wines[y] + winesProblem(x, y-1, i+1);
    return max(ans, ans2); 
}

// Recursion + Memoisation
int winesProblemTopDown(int x, int y, int i, int** dp)
{
    if(x > y)
    {
        return 0;
    }
    if(dp[x][y] != 0)
    {
        return dp[x][y];
    }
    int ans = i*wines[x] + winesProblemTopDown(x+1, y, i+1, dp);
    int ans2 = i*wines[y] + winesProblemTopDown(x, y-1, i+1, dp);
    return dp[x][y] = max(ans, ans2); 
}

// BottomUp Approach
int maxWine(int* wines, int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
   
    // Base Case 
    for(int i=0; i<n; i++)
    {
        dp[i][i] = (n)*wines[i];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            int smallAns1 = dp[j][j+i-1] + (n-i)*wines[j+i];
            int smallAns2 = dp[j+1][j+i] + (n-i)*wines[j];
            dp[j][j+i] = max(smallAns1, smallAns2);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int main()
{
    int ** arr = new int*[6];
    for(int i=0; i<6; i++)
    {
        arr[i] = new int[6];
    }
    
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            arr[i][j] = 0;
        }
    }
    // cout<<winesProblem(0, 4, 1)<<endl;
    cout<<winesProblemTopDown(0, 4, 1, arr)<<endl;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<maxWine(wines,5)<<endl;
}