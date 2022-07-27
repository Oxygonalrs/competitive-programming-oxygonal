/*

PRIME VISITS
PMO gives two random numbers a & b to the Prime Minister. 
PM Modi wants to visit all countries between a and b (inclusive), 
However due to shortage of time he can’t visit each and every 
country, So PM Modi decides to visit only those countries,
for which country number has two divisors. 

So your task is to find number of countries Mr. Modi will visit.

Input Format:
The first line contains N , no of test cases. The next lines contain two integers a and b denoting the range of country numbers.

Constraints:
a<=1000000 & b<=1000000.
N<=1000

Output Format:
Output contains N lines each containing an answer for the test case.

Sample Input:
2
1 10
11 20

Sample Output:
4
4

*/
#include<iostream>
using namespace std;
#define ll long long
void prime_sieve(int *p)
{
    for(int i=3; i<=1000000; i+=2)
    {
        p[i] = 1;
    }

    for(ll i=3; i<=1000000; i+=2)
    {
        if(p[i] == 1)
        {
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
    int p[1000005] = {0};
    prime_sieve(p);
    int csum[1000005] = {0};
    for(int i=1; i<=1000000; i++)
    {
        csum[i] = csum[i-1] + p[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<csum[b] - csum[a-1]<<endl;
    }
}
