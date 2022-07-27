#include<iostream>
using namespace std;

void merge(int *a, int start, int end)
{
    int mid = (start+end)/2;
    int arr[end-start+1] = {0};
    int i=start, j=mid+1;
    int k=0;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = a[j++];
        }
    }
    while(i<=mid)
    {
        arr[k++] = a[i++];
    }
    while(j<=end)
    {
        arr[k++] = a[j++];
    }
    k=0;
    cout<<endl;
    for(int i=start; i<=end; i++)
        a[i] = arr[k++];

}

void mergeSort(int *a, int start, int end)
{
    if(start >= end) return;
    int mid = (start+end)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    merge(a,start,end);
}

int main()
{
    int a[] = {6,5,4,3,2,1};
    int size = 6;
    mergeSort(a, 0, size-1);
    for(int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}