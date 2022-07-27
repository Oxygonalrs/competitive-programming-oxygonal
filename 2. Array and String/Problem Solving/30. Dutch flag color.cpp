//75 Leetcode
void sortColors(vector<int>& nums) {
    int zero=0;
    int one = 0;
    int two = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == 0) zero++;
        else if(nums[i] == 1) one++;
        else two++;
    }
    int i= 0;
    for(; i<zero; i++)
    {
        nums[i] = 0;
    }
    for(; i<one + zero; i++)
    {
        nums[i] = 1;
    }
    for(; i<two + zero + one; i++)
    {
        nums[i] = 2;
    }
}

//Single-parse solution
