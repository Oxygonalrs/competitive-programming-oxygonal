#include<iostream>
#include<cstring>
using namespace std;

int LCS(char* s1, char* s2)
{
    if(s1[0] == '\0' || s2[0] == '\0')
    {
        return 0;
    }
    if(s1[0] == s2[0])
    {
        return 1 + LCS(s1 +1, s2+1);
    }
    else{
        int option1 = LCS(s1, s2 +1);
        int option2 = LCS(s1 + 1, s2);
        return max(option2, option1);
    }
    return 0;
}

int LCS2Helper(char* s1, char *s2, int m, int n, int** dp)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }
    if(dp[m][n] > -1)
    {
        return dp[m][n];
    }
    int ans= 0;
    if(s1[0] == s2[0])
    {
        ans =  1 + LCS2Helper(s1 + 1, s2+1, m - 1, n-1, dp);
    }
    else{
        int option1 = LCS2Helper(s1, s2 +1, m, n-1, dp);
        int option2 = LCS2Helper(s1 + 1, s2, m - 1, n, dp);
        ans =  max(option2, option1);
    }
    dp[m][n] = ans;
    return ans;
}

//Dynamic Programming Recursive
int LCS2(char* s1, char* s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int **dp = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i] = new int[n+1];
        for(int j=0; j<=n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = LCS2Helper(s1, s2, m, n, dp);
    return ans;
}

//Dynamic Programming Iterative
int LCSIterative(char* s1, char* s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int **dp = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i] = new int[n+1];
    }
    for(int i=0; i<=m; i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0; j<=n; j++)
    {
        dp[0][j] = 0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            //In string start from 
            if(s1[m-i]==s2[n-j])
            // if(s1[i]==s2[j])
            {
                // cout<<s1[i]<<"I"<<s2[j]<<"J"<<endl;
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int ans = dp[m][n];
    return ans;
}

int main(){
    char a[100];
    char b[100];
    cin >> a >>b;
    // cout<<LCS2(a,b)<<endl;
    cout<<LCSIterative(a,b)<<endl;
    // cout<<LCS(a,b)<<endl;

}