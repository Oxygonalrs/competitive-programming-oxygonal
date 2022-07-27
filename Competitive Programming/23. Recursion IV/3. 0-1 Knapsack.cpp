#include<iostream>
#include<climits>
using namespace std;

int profit(int N, int C, int*wt, int *prices)
{
    if(N==0 || C==0)
    {
        return 0;
    }
    int inc,exc;
    if(wt[N-1] <=C)
        inc = prices[N-1] + profit(N-1, C - wt[N-1], wt, prices);
    exc = profit(N-1, C, wt, prices);
    int ans = max(inc, exc);
    return ans;
}

int main()
{
    int weight[] = {1, 2, 3, 5};
    int price[] = {40, 20, 30, 100};
    int N = 4;
    int C = 7;
    cout<<profit(N, C, weight, price);
}