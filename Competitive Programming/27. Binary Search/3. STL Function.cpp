#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {1,2,4,8,9,11,11,11,12,45};
    int n = 8;
    int key = 11;
    bool present = binary_search(arr, arr+n, key);
    auto it = lower_bound(arr, arr+n, key);
    
    //Gives index stricly greater than key
    auto it1 = upper_bound(arr, arr+n, key);

    cout<<it - arr<<endl;
    cout<<it1 - arr<<endl;
    cout<<"Frequency : "<<((it1 - arr) - (it -arr))<<endl;
}