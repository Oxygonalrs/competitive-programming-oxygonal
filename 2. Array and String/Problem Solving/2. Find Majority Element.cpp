#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

//Brute Force Approach
//take to for loop and check for each element
//and maintain count and ans

//O(n) -> make map and array element as key and count if found
int majorityElement(int *nums, int n)
{
    //Change Return type to void
    //O(n) -> space complexity
    // map<int, int> mpp;
    // int count = -1;
    // int ans = -1;
    // for(int i=0; i<n; i++)
    // {
    //     mpp[nums[i]]++;
    // }
    // for(auto i : mpp)
    // {
    //     if(i.second != 1 && i.second > count)
    //     {
    //         ans = i.first;
    //     }
    // }
    // return ans;

    //O(1) -> space
    //Boyer-Noor Algotithm
    //if m>n/2 then we can use this algorithm
    
        sort(nums,nums + n);
        // sort(nums.begin(),nums.end());
        reverse(nums, nums + n);
        // reverse(nums.begin(), nums.end());
        // for(int i=0; i<n; i++)
        //     cout<<nums[i]<<" ";
        // cout<<endl;
        int m = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(count == 0)
            {
                m = nums[i];
                // cout<<"M "<<m<<endl;
                count++;
            }
            else if(nums[i] == m)
            {
                // cout<<"M "<<m<<endl;
                count++;
            }
            else{
                count--;
            }
        }
        // count = 0;
        // for(int i=0; i<n; i++)
        // {
        //     if(m == nums[i])
        //     {
        //         count++;
        //     }
        // }
        return m;
}


int main()
{
    int a[] = {4,1,4,2,4};
    int n=7;
    cout<<majorityElement(a, n);
    return 0;
}