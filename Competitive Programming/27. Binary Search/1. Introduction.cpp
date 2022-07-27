#include<iostream>
using namespace std;

int binary_search(int* a, int n, int data)
{
    int s = 0;
    int e = n-1;
    
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(a[mid] == data)
        {
            return mid;
        }
        else if(a[mid]> data)
        {
            e = mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {1,2,3,5,7,10,11,12,15};
    int n = 9;
    cout<<binary_search(a, n, 10)<<endl;
}