#include <iostream>
using namespace std;

//Finding the Number of Set Bits 
//Time Complexity O(logN)
//long long int -> 10^18
//log -> 64

// int countBits(int n)
// {
//     int ans = 0;
//     while(n>0)
//     {
//         ans += (n&1);
//         n = n>>1;
//     }
//     return ans;
// }


//O(no of set bits)
int countBits(int n)
{
    int ans = 0;
    while(n>0)
    {                 //5&4 = 1 0 1 & 1 0 0 = 1 0 0 & 0 1 1 = 0 0 0
        n = n&(n-1);  //It actually remove last bit right -> left
        ans++;
    }
    return ans;
}


int main()
{
    cout<<countBits(15)<<endl;
    cout<<__builtin_popcount(15)<<endl;
    return 0;
}