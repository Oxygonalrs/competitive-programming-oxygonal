//Maximum Profit on App
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int maxi = 0;
    for(int i=0; i<n; i++)
    {
        int m = 0;
        for(int j=0; j<n; j++)
        {
            if(a[i] <= a[j])
            {
                m++;
            }
        }
        maxi = max(maxi, a[i]*m);
    }
    cout<<maxi;
    return 0;
}