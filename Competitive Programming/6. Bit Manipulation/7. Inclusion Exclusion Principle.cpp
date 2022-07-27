// How many numbers is less than 1000
// ans they are divisible by 2, 3, 5

// INPUT 1<=t<=10 1<=n<=10^18

#include<iostream>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin>>t;
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    while(t--)
    {
        ll n;
        cin>>n;
        ll subsets = (1<<8) - 1;
        ll ans = 0;
        for(ll i=1; i<=subsets; i++)
        {
            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);
            for(int j=0; j<8; j++)
            {
                if(i&(1<<j))
                {
                    denom = denom*primes[j];
                }
            }
            if(setBits&1)
            {
                ans += n/denom;
            }
            else{
                ans -= n/denom;
            }
        }
        cout<<ans<<endl;
    }
}