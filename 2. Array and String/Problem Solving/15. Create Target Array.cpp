#include<iostream>
#include<vector>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> v;
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        if(v.size() <= index[i])
        {
            v.push_back(nums[i]);
        }
        else{
            v.insert(v.begin() + index[i], nums[i]);
        }
    }
    return v;
}

int main()
{

    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;



// int main()
// {

//     return 0;
// }