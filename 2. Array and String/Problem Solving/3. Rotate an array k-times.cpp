#include<iostream>
using namespace std;

void reverse(int *a, int l, int h)
{
    int i = l; 
    int j = h;
    while(i<j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

//Rotate an array k-time
void rotateArray(int *nums, int n, int k)
{
    // O(n^2) -> Time && O(1) -> Space
    // if(k==0 || k==n) return;
    // for(int i=0; i<k; i++)
    // {
    //     int temp = nums[n-1];
    //     for(int j=n-1; j>0; j--)
    //     {
    //         nums[j] = nums[j-1];
    //     }
    //     nums[0] = temp;
    // }

    //BY using additional space for k element
    //Repeat upper code

    //O(n) -> Time and O(1) -> space
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-k-1);
    reverse(nums,0,n-1);
}

int main()
{
    int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    rotateArray(a, n, 2);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}