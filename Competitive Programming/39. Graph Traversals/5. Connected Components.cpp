#include<bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    list<pair<int, int>> * l;
    public:
    Graph(int n)
    {
        this->n = n;
        l = new list<pair<int, int>>[n+1];
    }

    void addEdge(int x, int y, int z)
    {
        l[x].push_back(make_pair(y,z));
        l[y].push_back(make_pair(x,z));
    }

    int minCost(vector<int> &v)
    {
        int ans = INT_MAX;
        for(auto i : v)
        {
            for(auto j : l[i])
            {
                ans = min(ans, j.second);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

int main()
{
    int n,m,k,x,y,z;
    vector<int> v;
    cin>>n>>m>>k;
    Graph g(n);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;
        g.addEdge(x, y, z);
    }
    for(int i=0; i<k; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<g.minCost(v);
}