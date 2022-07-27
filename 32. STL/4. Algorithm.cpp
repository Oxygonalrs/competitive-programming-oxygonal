#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int arr[] = {2, 10, 11, 9, 100};
    int n = sizeof(arr)/sizeof(int);

    int key = 11;
    auto it = find(arr, arr+n, key);
    cout<<(it - arr)<<endl;
}