#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

// 0-1 Knapsack means we can't fraction of weight
/*
If I take that item then 
dp[n][w] = value + dp(n-1, w - weight)
           dp(n-1, w)
*/
class Item{
    public:
    long long weight;
    long long value; 
};

long long maxPoint(Item *arr, int n, int w)
{
    int dp[n][w];
    for(int i=0; i<n;)
     
}

int main(){
    int n, w;
    cin>>n>>w;
    Item arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].weight>>arr[i].value;
    }
    cout<<maxPoint(arr, n, w);
}