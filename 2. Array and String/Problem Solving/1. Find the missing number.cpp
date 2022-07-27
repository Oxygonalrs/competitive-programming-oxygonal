#include<iostream>
using namespace std;

int missingNumber(int *a, int n)
{
    //add all element and subtract from sum of n  first number
    //But n = INT_MAX then it overflow
    int sum = (n+2)*(n+1)/2;
    for(int i=0; i<n; i++)
        sum-=a[i];
    return sum;

    //XOR-base solution
    int sum1 = 1;
    int sum2 = a[0];
    for(int i=2;i<=n+1;i++)
        sum1 = sum1^i; 
    for(int i=1;i<n+1;i++)
        sum2 = sum2^a[i];
    return sum1^sum2;
}

int main()
{
    int a[] = {1, 2, 4, 3, 6, 7, 9, 8, 10};
    int n = 9;
    cout<<missingNumber(a,n)<<endl;
}