#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<unordered_map>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> neighbours;
    public:
    void addEdge(T x, T y)
    {
        neighbours[x].push_back(y);
        neighbours[y].push_back(x);
    }
    void bfs(T start)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int nbr : neighbours[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void SSSP(T start)
    {
        map<T, int> dist;
        queue<T> q;
       
        for(auto node_pair : neighbours)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(start);
        dist[start] = 0;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int nbr : neighbours[node])
            {
                if(dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        for(auto node_pair: neighbours)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout<<"Node "<<node<< "  Dist "<<d<<endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.SSSP(0);
    // g.bfs(0);
}