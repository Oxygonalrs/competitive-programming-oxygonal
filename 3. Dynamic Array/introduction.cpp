#include<iostream>
using namespace std;

int main()
{
    int i;
    cout<<&i<<endl;
    int *p = &i;
    cout<<sizeof(p)<<endl;
    // cout<<*  p;
    int arr[5];int *a = arr;
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<arr+1<<endl;
    cout<<a+1<<endl;
    cout<<*a<<endl;
    return 0;
}