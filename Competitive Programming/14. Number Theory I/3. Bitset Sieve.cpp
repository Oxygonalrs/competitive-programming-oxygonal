#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long

//More Space = More Range of Prime Numbers you can store
// bitset<100> b;  ->100 bits
// bool b[100];  -> 100 Byte = 800 Bits

const int n = 10000000;
bitset<10000000> b;
vector<int> primes;

void sieve()
{
    b.set(); //1, 1, 1,....
    b[0] = b[1] = 0;
    for(long long int i=2; i<=n; i++)
    {
        if(b[i])
        {
            primes.push_back(i);
            for(long long int j = i*i; j<=n; j+=i) //for 10^7 * 10^7 that will wrong answer or segmentation fault   q
            {
                b[j] = 0;
            }
        }
    }
}

bool isPrime(long long No)
{
    if(No<=n)
    {
        return b[No] = 1 ? true : false;
    }
    for(long long int i=0; primes[i]*(long long)primes[i]<=No; i++)
    {
        if(No% primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    sieve();
    if(isPrime(21474836478916))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<" NO "<<endl;
    }
    for(int i=0; i<=200; i++)
    {
        cout<<primes[i]<<" ";
    }
}