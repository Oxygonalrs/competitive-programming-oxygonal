#include<iostream>
using namespace std;

int maxLCS(string s1, string s2, int i, int j)
{
    if(s1.size() == i || s2.size() == j) return 0;

    if(s1[i] == s2[j])
    {
        return 1 + maxLCS(s1, s2, i+1, j+1);
    }
    else{
        return max(maxLCS(s1, s2, i+1, j), maxLCS(s1, s2, i, j+1));
    }
}

int maxLCSTopDown(string s1, string s2, int i, int j, int** dp)
{
    if(s1.size() == i || s2.size() == j) return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
    {
        return dp[i][j] = 1 + maxLCSTopDown(s1, s2, i+1, j+1, dp);
    }
    else{
        return dp[i][j] =  max(maxLCSTopDown(s1, s2, i+1, j, dp), maxLCSTopDown(s1, s2, i, j+1, dp));
    }
}

int lcs(char *X, char *Y, int m, int n)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}

int main()
{
    string s1 = "FGHIJ";
    string s2 = "ABCDE";
    int ** dp = new int*[s1.size()];
    for(int i=0; i<s1.size(); i++)
    {
        dp[i] = new int[s2.size()];
        for(int j=0; j<s2.size(); j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<maxLCS(s1, s2, 0, 0)<<endl;
    
    cout<<maxLCSTopDown(s1, s2, 0, 0, dp)<<endl;
    for(int i=0; i<s1.size(); i++)
    {
        // dp[i] = new int[s2.size()];
        for(int j=0; j<s2.size(); j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}