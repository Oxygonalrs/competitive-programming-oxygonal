#include<iostream>
using namespace std;

// template<class T>
template<typename T>
int search(T arr[], int n, T key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return n;
}

int main()
{
     int a[] = { 4, 8, 9, 6 , 1, 10};
     int n = sizeof(a)/sizeof(int);
     cout<<search(a, n, 10);cout<<endl;
     float b[] = {1.9, 1.3, 1.4, 1.6, 1.2};
     n = sizeof(b) / sizeof(float);
     float key = 1.2;
     cout<<search(b, n, key);
}