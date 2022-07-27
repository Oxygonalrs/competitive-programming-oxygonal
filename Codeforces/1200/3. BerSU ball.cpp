#include<iostream>
#include<algorithm>
#include<climits>
#include<limits>
using namespace std;

// https://codeforces.com/problemset/problem/489/B

int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    int i=0, j=0;
    int ans = 0;
    while(i<n && j<m)
    {
        if(abs(a[i] - b[j]) <= 1)
        {
            ans++;
            i++;
            j++;
        }
        else{
            a[i] < b[j] ? i++ : j++;
        }
    }
    cout<<ans<<endl;
}