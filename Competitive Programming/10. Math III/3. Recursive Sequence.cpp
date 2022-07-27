/*
Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.

Input
On the first row there is the number C of test cases (equal to about 1000).
Each test contains four lines:

k - number of elements of (c) and (b) (1 <= k <= 10)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
n - natural number (1 <= n <= 109)

Output
Exactly C lines, one for each test case: an modulo 109
*/

#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define MOD 1000000000

ll k;
vector<ll> a, b, c;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    // Lets store the result in som matrix C
    vector<vector<ll>> C(k+1, vector<ll>(k+1));
    // Logic to multiply matrices
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=k; j++)
        {
            for(int x=1; x<=k; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll p)
{
    if(p==1)
    {
        return A;
    }

    //power is odd
    if(p&1)
    {
        return multiply(A, pow(A, p-1));
    }
    
    vector<vector<ll>> X = pow(A, p/2);
    return multiply(X, X);
}

ll compute(ll n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n<=k)
    {
        return b[n-1];
    }

    // Otherwise use matrix exponentiation
    vector<ll> F1(k+1);     // 1-Based indexing
    
    // Step - 1
    for(int i=1; i<=k; i++)
    {
        F1[i] = b[i-1];
    }

    // Step - 2
    vector<vector<ll>> T(k+1, vector<ll>(k+1));
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i<k)
            {
                // Fill 0s and 1s
                if(j==i+1)
                {
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
            }
            else{
                T[i][j] = c[k-j];
            }
        }
    }

    // Step - 3
    T = pow(T, n-1);

    // Step - 4
    // Matrix with A vector
    ll res = 0;
    for(int i=1; i<=k; i++)
    {
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }
    return res;
}

int main()
{
    ll t, n, num;
    cin>>t;
    while(t--)
    {
        cin>>k;

        //Init vector F1
        for(int i=0; i<k; i++)
        {
            cin>>num;
            b.push_back(num);
        }

        //Coefficients
        for(int i=0; i<k; i++)
        {
            cin>>num;
            c.push_back(num);
        }

        cin>>n;
        cout<<compute(n)<<endl;
        b.clear();
        c.clear();
    }

}