#include<iostream>
#include<queue>
#include<cstring>
#include<list>
#include<map>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;
    public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
    }
    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;

        for(T nbr : l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr, visited,ordering);
            }
        }
        ordering.push_front(src);
    }
    void dfs()
    {
        map<T, bool> visisted;
        list<T> ordering; 
        for(auto p : l)
        {
            T node = p.first;
            visisted[node] = false;
        }
        for(auto p : l)
        {
            T node = p.first;
            if(!visisted[node]) 
            {
                dfs_helper(node, visisted, ordering);
            }
        }
        for(auto p : ordering)
        {
            cout<<p<<endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("Python", "DataProcessing");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataProcessing", "ML");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecognition");
    g.addEdge("DataSet", "FaceRecognition");

    g.dfs();
}