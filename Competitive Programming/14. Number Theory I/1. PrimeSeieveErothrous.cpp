/*
Prime Sieve
In normal time -> O(N)
Optimize time -> O(N^(1/2))

complexity N/2 + N/3 + N/5 + n/7+ ...
 = N* (1/2 + 1/3+ 1/5+ 1/7+...)
 = O(N*LogLogN)   //Almost Linear
*/

#include<iostream>
using namespace std;

#define ll long long

void prime_sieve(int *p)
{
    //First mark all odd number's prime
    for(int i=3; i<=1000000; i+=2)
    {
        p[i] = 1;
    }

    //Sieve
    for(ll i=3; i<=1000000; i+=2)
    {
        //if the current number is not marked (it is prime)
        if(p[i] == 1)
        {
            //mark all the multiple of i as not prime
            for(ll j = i*i; j<=1000000; j+=i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;
}

int main()
{
    int n;
    cin>>n;
    int p[1000005] = {0};
    prime_sieve(p);
    for(int i=0; i<=n; i++)
    {
        if(p[i] == 1)
        {
            cout<<i<<" ";
        }
    }
}