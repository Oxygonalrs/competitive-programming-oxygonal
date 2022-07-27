#include<iostream>
using namespace std;

//Compute HCF and GCD

//Euclid's Algorithm
int gcd(int a, int b)
{
    return b==0 ? a : gcd(b, a%b);
}

// gcd*lcm = a*b
// lcm = a*b/gcd;
// a%b = a - (a/b)*b

// T(n) = T(n/2) + k
// T(n/2) = T(n/4) + k
// T(1) =  + k

// T(n) =   Ek
// O(logN)
int main()
{
    int n1, n2;
    // cin>>n1>>n2;
    cout<<gcd(96, 96);
}