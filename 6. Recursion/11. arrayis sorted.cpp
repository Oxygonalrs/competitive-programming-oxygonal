#include<iostream>
using namespace std;

bool is_sorted(int a[], int size)
{
    if(size == 0||size==1)
    {
        return true;
    }
    if(a[0] > a[1])
    {
        return false;
    }
    bool isSmallerSorted = is_sorted(a+1, size-1);
    return isSmallerSorted;
}

bool is_sortedFromEnd(int *a, int size)
{
    if(size == 0 || size == 1)
        return true;
    if(a[size]<a[size-1])
        return false;
    bool isSmallerSorted = is_sortedFromEnd(a, size-1);
    return isSmallerSorted;
}

int firstIndex(int a[], int size, int k)
{
    if(size == 0) return -1;
    if(a[0] == k) return 0;
    int preindex = firstIndex(a+1,size-1,k);
    if(preindex == -1) return -1;
    int index = 1 + preindex;
    return index; 
}

int lastIndex(int a[], int size, int k)
{
    if(size == 0) return -1;
    if(a[size-1] == k) return size-1;
    int preindex = lastIndex(a,size-1,k);
    //if(preindex == -1) return -1;  
    return preindex; 
}

int sum(int a[], int size)
{
    if(size == 1) return a[0];
    int prevsum = sum(a+1, size-1);
    int sum = a[0] +prevsum;
    return sum;
}

//Return all indicess 
//We can vector that be easy
int findallIndex(int a[], int size, int k, int *output)
{
    if(size == 0) return 0;
    int preindex = findallIndex(a,size-1,k, output);
    if(a[size-1]==k)
    {
        output[preindex] = size - 1;
        cout<<output[preindex];
        return 1 + preindex;
    }
    return preindex;
}

int main()
{
    int arr[] = {5,6,5,5,6};
    int *output = new int[5];
    for(int i=0; i<5; i++)
        output[i] = 0;
    //cout<<is_sorted(arr, 5)<<endl;
    cout<<"My Array From Last: "<<is_sortedFromEnd(arr, 5)<<endl;
    cout<<firstIndex(arr, 5, 8)<<endl;
    cout<<lastIndex(arr, 5, 8)<<endl;
    cout<<"FindAllIndex: "<<findallIndex(arr, 5, 5, output)<<endl;
    for(int i=0; i<5; i++) cout<<output[i]<<" ";
    //cout<<sum(arr, 5)<<endl;
    return 0;
}