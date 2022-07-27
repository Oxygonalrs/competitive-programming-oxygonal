#include<bits/stdc++.h>
using namespace std;
//Maximize the sum of Two Array
int maximumSum(int a[], int b[])
{
    int sum1 = 0;
    int sum2 = 0;
    int i=0, j=0;
    int maxSum = 0;
    while(i<4 || j<5)
    {
        if(a[i] == b[j]) {
            maxSum = max(sum1, sum2) + b[j];
            sum1 = sum2 = 0;
            i++;
            j++; 
        }
        if(a[i] < b[j]) sum1 += a[i++];
        else sum2 += b[j++];
    }
    
    
    maxSum += max(sum1, sum2);
    return maxSum;
}

//Merge Two SortedArray
void sortedArray(int a[], int b[], int c[])
{   int i = 0, j=0, k=0;
    while(i<4 && j<5)
    {
        if(a[i]<=b[j])
        {
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }       
    }
    while(i!=4)
    {
        c[k++] = a[i++];
    }
    while(j!=5)
    {
        c[k++] = b[j++];
    }
}

int main()
{
    int a[4] = {1,9,10,12};
    int b[5] = {1,6,15,20,40};
    int c[9] = {0};
    sortedArray(a,b,c);
    for(int i=0;i<9;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    cout<<"Sum: "<<maximumSum(a,b);
    return 0;
}