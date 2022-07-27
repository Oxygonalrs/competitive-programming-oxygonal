#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> smallerNumbersThanCurrent(int* nums, int n) {
    //Brute Force Approach
    vector<int> v;
    // for(int i=0; i<n; i++)
    // {
    //     int a = nums[i];
    //     int count = 0;
    //     for(int j=0; j<n; j++)
    //     {
    //         if(a>nums[j]) count++;
    //     }
    //     v.push_back(count);
    // }
    // return v;

    //Sort input array
    //O(nlogn) -> Time and O(n) -> size
    int a[n];
    for(int i=0; i<n; i++)
        a[i] = nums[i];
    sort(a, a+n);
    
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++)
    {   
        if(mpp.count(a[i]) > 0) continue;
        else mpp[a[i]] = i;
    }
    
    for(int i=0; i<n; i++)
    {
        v.push_back(mpp[nums[i]]);
    }
    return v;

    //O(n) -> Time ans O(1) -> space
    //contraint is very small so we can make array of that size
    //nums[i] <= 100
    // int a[100] = {0};
    // for(int i=0; i<n; i++)
    // {
    //     if(a[nums[i]] == 0)
    //         a[nums[i]]++;
    // }
    // int count = 0;
    // for(int i=0; i<100;i++)
    // {
    //     a[i] = a[i] + count;
    //     count = a[i];
    // }
    // for(int i=0; i<n; i++)
    // {
    //     v.push_back(a[nums[i]] - 1);
    // }
    // return v;
}

int main()
{
    int a[] = {8,1,2,2,3};
    int n = 5;
    vector<int> v = smallerNumbersThanCurrent(a, n);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}