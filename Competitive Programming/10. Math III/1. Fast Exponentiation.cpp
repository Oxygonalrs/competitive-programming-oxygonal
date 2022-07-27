/*
Fast Exponentiation and can be solved using bit Manipulations also
Faster way to cmpute a^n
pow(a,n);

a^n = a(a^(n/2))^2   // n is odd
a^n = (a^(n/2))^2   // n is Even

5^11 = 5(5^5)^2 -> 5(5^2)^2 -> 5(5^1)^2 -> 5(5^0)^2
2^8 = (2^4)^2 -> (2^2)^2 -> (2^1)^2 -> 2(2^0)^2
*/

#include <iostream>
using namespace std;

//O(logN)
int pow(int a, int n)
{
    if(n==0)
    {
        return 1;
    }
    int subprob = pow(a, n/2);
    if(n&1)
    {
        return a* subprob * subprob;
    }
    return subprob*subprob;
}

int main()
{
    cout<<pow(2,10);
}