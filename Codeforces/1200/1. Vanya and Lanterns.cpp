#include<iostream>
#include<algorithm>
#include<climits>
#include<limits>
using namespace std;

// https://codeforces.com/problemset/problem/492/B

int main()
{
    int n, l;
    cin>>n>>l;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    double ans = 0.0;
    if(n == 1)
    {
        ans = max(ans, (1.0*(a[0]) - 0));
        ans = max(ans, l - (1.0*(a[0])));
    }
    else{
        sort(a, a+n);
        for(int i=1; i<n; i++)
        {
            ans = max(ans, (1.0*(a[i] - a[i-1]))/2);
        }

        ans = max(ans, (1.0*(a[0]) - 0));
        ans = max(ans, l - (1.0*(a[n-1])));
    }

    
    cout.precision(10);
    cout<<ans<<endl;
}