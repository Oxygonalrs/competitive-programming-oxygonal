#include<iostream>
using namespace std;

int firstOccurance(int a[], int n, int data)
{
    int s = 0;
    int e = n-1;
    int index = -1;
    while(s<=e)
    {
        int mid = (s + e)/2;
        if(a[mid] == data)
        {
            index = mid;
            e = mid - 1;
        }
        else if(a[mid] > data)
        {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return index;
}

int lastOccurance(int a[], int n, int data)
{
    int s = 0;
    int e = n-1;
    int index = -1;
    while(s<=e)
    {
        int mid = (s + e)/2;
        if(a[mid] == data)
        {
            index = mid;
            s = mid + 1;
        }
        else if(a[mid] > data)
        {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return index;
}

int main()
{
    int a[] = {1,2,5,8,8,8,8,8,10,12,15,20};
    int n = sizeof(a)/sizeof(int);
    cout<<firstOccurance(a,n, 8);
    cout<<endl;
    cout<<lastOccurance(a,n, 8);
    
}