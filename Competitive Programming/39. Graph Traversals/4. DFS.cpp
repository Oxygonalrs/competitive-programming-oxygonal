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
    void dfs_helper(T start, map<T, bool> &visited)
    {
        cout<<start<<" ";
        visited[start] = true;
        for(auto i : neighbours[start])
        {
            if(!visited[i])
            {
                dfs_helper(i, visited);
            }
        }
    }
    void dfs(T start)
    {
        map<T, bool> visited;
        for(auto i : neighbours)
        {
            T node = i.first;
            visited[node] = false;
        }
        dfs_helper(start, visited);
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

    g.bfs(0);
    cout<<endl;
    g.dfs(0);
}