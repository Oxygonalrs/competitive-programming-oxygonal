#include<iostream>
using namespace std;

void BubbleSort(int *a, int j, int n)
{
    if(n==0 || n==1)
    {
        return;
    }
    if(j == n-1)
    {
        BubbleSort(a, 0, n-1);
        return;
    }
    if(a[j] > a[j+1])
    {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
    }
    BubbleSort(a, j+1, n);
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    BubbleSort(arr, 0, 9);
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}