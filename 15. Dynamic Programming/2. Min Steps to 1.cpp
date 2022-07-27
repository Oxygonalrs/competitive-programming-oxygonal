#include<iostream>
using namespace std;

//Brute Force Approach
int minStep(int n)
{
    int rem = n;
    if(n == 1) return 0;
    if(n%3 == 0)
    {
        rem = minStep(n/3);
    }
    if(n%2==0)
    {
        rem = min(rem, minStep(n/2));
    }
    rem = min(rem, minStep(n-1));
    return rem + 1;
}

//Memoisation
int minStepR(int n, int* arr)
{
    if(n == 1) return 0;
    if(arr[n] > 0) return arr[n];
    int rem = 7;
    if(n%3 == 0)
    {
        rem = minStep(n/3);
    }
    if(n%2==0)
    {
        rem = min(rem, minStep(n/2));
    }
    rem = min(rem, minStep(n-1));
    arr[n] = rem + 1;
    return arr[n];
} 

//DP by iterative
int minStepI(int n)
{
    int arr[n+1] = {0};
    arr[1] = 0;
    for(int i=2; i<=n; i++)
    {
        int rem = n;
        if(i%3 == 0)
        {
            rem = min(rem, arr[i/3]);
        }
        if(i%2 == 0)
        {
            rem = min(rem, arr[i/2]);
        }
        rem = min(rem, arr[i-1]);
        arr[i] = rem + 1;
    }
    return arr[n];
}

int main()
{
    int n;
    cin>>n;
    int a[n+1] = {0};
    cout<<"By Recursion: "<<minStep(n)<<endl;
    cout<<"By Iterative: "<<minStepI(n)<<endl;
    cout<<"By Memoisation: "<<minStepR(n, a)<<endl;
    return 0;
}