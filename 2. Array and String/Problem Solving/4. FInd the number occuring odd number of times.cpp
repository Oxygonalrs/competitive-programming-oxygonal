#include<iostream>
using namespace std;

//Brute force approach is O(n^2) by using two loops

//Second Approach by using map
//O(n) -> Time and O(n) -> space 

//By using XOR operation
//But is required one element having odd number
int oddNumber(int *nums, int n)
{
    int ans=0;
    for(int i=0; i<n; i++){
        ans = ans^nums[i];
    }
    return ans;
}

int main()
{
    int a[] = {1,4,5,9,2,2,8,2,1,6,7};
    int n = 9;
    cout<<oddNumber(a, n);
    return 0;
}