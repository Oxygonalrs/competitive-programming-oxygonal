#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

class Activity{
    public:
    int a;
    int b; 
    int c;
};

int maxPoint(Activity *arr, int n)
{
    Activity dp[n];
    dp[0].a = arr[0].a;
    dp[0].b = arr[0].b;
    dp[0].c = arr[0].c;

    for(int i=1; i<n; i++)
    {
        dp[i].a = arr[i].a + max(dp[i-1].b, dp[i-1].c);
        dp[i].b = arr[i].b + max(dp[i-1].a, dp[i-1].c);
        dp[i].c = arr[i].c + max(dp[i-1].a, dp[i-1].b);
    }
    return max(dp[n-1].a, max(dp[n-1].b, dp[n-1].c));
}

int main(){
    int n;
    cin>>n;
    Activity arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    }
    cout<<maxPoint(arr, n);
}