// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> n;
    public:
    void addEdge(T u, T v, int dist)
    {
        n[u].push_back(make_pair(v, dist));
    }
    void printAdj()
    {

    }
    void dijsktraSSS(T src)
    {
        unordered_map<T, int> dist;
        for(auto j : n)
        {
            dist[j.first] = INT_MAX;
        }

        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for(auto childPair : n[node])
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for(auto i : dist)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
};

int main()
{

    return 0; 
}