#include<iostream>
using namespace std;

/*
Recursion in CS is a method where solution to a problem depends
on solution to smaller instances of the same problem

*/
bool isSorted(int * a, int size)
{
    if(size == 0 || size == 1)
    {
        return true;
    }
    if(a[0] > a[1])
    {
        return false;
    }
    return isSorted(a+1, size-1);
}

int firstOcc(int *a, int n, int key)
{
    if(n == 0)
    {
        return -1;
    }
    if(a[0] == key)
    {
        return 0;
    }
    int smallOutput =  firstOcc(a+1, n-1, key);
    if(smallOutput == -1) return -1;
    return 1 + smallOutput;
}

int main()
{
    int arr[] = {1,2,3,6,5};
    cout<<firstOcc(arr, 5, 22);
}