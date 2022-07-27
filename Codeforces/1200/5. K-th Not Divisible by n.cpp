#include<iostream>
#include<algorithm>
#include<climits>
#include<limits>
using namespace std;

// https://codeforces.com/problemset/problem/1352/C

int main()
{
    long long int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int x = n-1;
        long long int cal = x;
        long long calMain = 1;
        long long increament = 1;
        while(k - cal*increament > x)
        {
            increament++;
        }
        cal = x*increament;
        calMain = n*increament;
        while(cal != k)
        {
            calMain++;
            cal++;
        }
        cout<<calMain<<endl;
    }
}