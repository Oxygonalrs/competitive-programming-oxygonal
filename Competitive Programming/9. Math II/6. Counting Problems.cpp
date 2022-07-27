//Counting Problems | Inclusion Exclusion Principle

//How many numbers 1 to 100 are multiple of 2 or 3
// A -> multiple of 2 [100/2] = 50
// B -> multiple of 3 [100/3] = 33
// C -> multiple of 6 [100/6] = 16
// 50 + 33 - 16 = 67

//How many no's are less than 1000 and they are divisible by 2,3,5
// 1...999
// A -> divisible by 2 [999/2] = 449
// B -> divisible by 3 [999/3] = 333
// C -> divisible by 5 [999/5] = 199

// |2| + |3| + |5| - |2^3| - |2^5| - |3^5| + [2^3^5]
// D -> divisble by 2 and 3 = 6 999/6 = 166
// D -> divisble by 2 and 5 = 10 999/10 = 199
// D -> divisble by 3 and 5 = 6 999/15 = 66
// G -> divisible by 2, 3 and 5 = 30 999/30 = 33

//Total -> 733

//a = [2,3,5] and < N
// 1) Generate all subsets by bitmasking

//primes < 20
//[2, 3, 5, 7, 11, 13, 17, 19]

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

        ll subsets = (1<<8) - 1; //2^8 - 1
        ll ans = 0;
        for(ll i = 1; i<=subsets; i++)
        {
            ll denom = 1ll;  // 1
            ll setBits = __builtin_popcount(i);
            for(ll j=0; j<=7; j++) //bits 0 0 0 0 0 0 0
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
                ans -= n/ denom;
            }
        }
        cout<<ans<<endl;
    }
}