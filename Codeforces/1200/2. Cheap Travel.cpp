#include<iostream>
#include<algorithm>
#include<climits>
#include<limits>
using namespace std;

// https://codeforces.com/problemset/problem/466/A

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(a*m <= b)
    {
        cout<<n*a<<endl;
    }
    else{
        int div = n/m;
        int rem = n%m;
        int ans = min(div*b + rem*a, b*(div+1));
        cout<<ans<<endl; 
    }
}