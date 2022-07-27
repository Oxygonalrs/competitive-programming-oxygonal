#include<iostream>
using namespace std;

int maxSum(int *a, int n)
{
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int max_so_far = dp[0];
    for(int i=1; i<n; i++)
    {
        dp[i] = dp[i-1] + a[i];
        if(dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_so_far = max(dp[i], max_so_far);
    }
    return max_so_far;
}

//It is known as Kadane's Algorithm
int maxSumOptimized(int *a, int n)
{
    int previousElement = a[0] > 0 ? a[0] : 0;
    int max_so_far = previousElement;
    for(int i=1; i<n; i++)
    {
        previousElement = previousElement + a[i];
        if(previousElement < 0)
        {
            previousElement = 0;
        }
        max_so_far = max(previousElement, max_so_far);
    }
    return max_so_far;
}

int main()
{
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSum(arr, n)<<endl;
    cout<<maxSumOptimized(arr, n)<<endl;
}