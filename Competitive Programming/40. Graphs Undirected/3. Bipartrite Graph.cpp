#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
const int N = 100005, M=22;
vector<int> gr[N];
int vis[N];
void dfs(int cur, int par, int col)
{
    vis[cur] = col;
    for(auto child : gr[cur])
    {
        if(vis[child] == 0)
            dfs(child, cur);
        else if(child != par && col == vis[child])
        {

        }
    }
}
void solve()
{
    int i, j, k, n, m, ans = 0, cnt =0, sum = 0;
    for(i=0; i<m; i++)
    {
        int x, y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1, 0);
}