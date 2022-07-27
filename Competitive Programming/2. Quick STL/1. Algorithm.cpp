#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int arr[] = {1, 10, 11, 11, 11, 93, 100};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    //Find
    // int key;
    // cin>>key;
    // auto it = find(arr,arr+n, key);
    // int index = it - arr;
    // cout<<index<<endl;

    //Binary Search
    bool present = binary_search(arr,arr+n, key);
    cout<<present<<endl;

    //>= key
    auto it = lower_bound(arr, arr+n, key);
    auto it2 = upper_bound(arr, arr+n, key);
    cout<<(it - arr)<<" "<<(it2-arr)<<endl;
}