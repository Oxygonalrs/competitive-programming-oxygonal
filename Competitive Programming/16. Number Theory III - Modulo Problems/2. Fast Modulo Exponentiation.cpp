/*
a^b % m 

-> Linear Time
-> O(logb) Time

For eg 3^5

5 -> 1 0 1

Traverse from right to left
if it is 1 then multiply by that index

*/

#include<iostream>
using namespace std;

#define ll long long
ll fastModExp(ll a, ll b, ll m)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)
        {
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}

int main(){
    cout<<fastModExp(5, 3, 100)<<endl;
}