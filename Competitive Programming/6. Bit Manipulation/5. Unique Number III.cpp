#include<iostream>
using namespace std;

// All Number occur thrice except one
// 3 3 2 1 1 1 3    3N or 3N+1 
// 0 1 1
// 0 1 1
// 0 1 0
// 0 0 1
// 0 0 1
// 0 0 1
// 0 1 1

// 0 4 6    Take Modulo by 3  -> 0 1 0 => 2
int main()
{
    int cnt[64] = {0};
    int n, no;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>no;
        int j=0;
        while(no > 0)
        {
            int last_bit = (no & 1);
            cnt[j] += last_bit;
            j++;
            no = no>>1;
        }
    }
    // Iterate over the array
    int ans = 0;
    int p = 1;
    for(int i=0; i<64; i++)
    {
        cnt[i] = cnt[i]%3;
        ans+=p*cnt[i];
        p = p<<1;
    }
    cout<<ans<<endl;
}