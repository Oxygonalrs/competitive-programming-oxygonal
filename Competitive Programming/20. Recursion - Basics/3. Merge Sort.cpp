#include<iostream>
using namespace std;

void MergeArray(int* a, int s, int n)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[e+1];
    
}

void MergeSort(int* a, int s, int n)
{
    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2;
    MergeSort(a, s, mid);
    MergeSort(a, mid+1,e);
    MergeArray(a, s, e);
}

int main()
{
    int arr[] = {9,8,5,7,6,6,7,3,5};
    return 0;
}