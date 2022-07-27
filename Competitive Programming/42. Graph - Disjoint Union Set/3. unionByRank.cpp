//Attach smaller tree to bigger tree
//O(1) -> almost
//Research is necessary
#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>> l;
    
    int findSet(int* parent, int i)
    {
        if(parent[i] == -1)
        {
            return i;
        }
        parent[i] = findSet(parent, parent[i]);
        return parent[i];
    }

    void unionSet(int* parent, int s1, int s2, int* rank)
    {
        if(s1 != s2)
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }        
        }
    }
    
    public:
    Graph(int V){
        this->V = V;
    }
    
    void addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }
    
    bool containCycle()
    {
        int * parent = new int[V];
        int * rank = new int[V];
        for(int i=0; i<V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
        for(auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(parent, i);
            int s2 = findSet(parent, j);
            if(s1 != s2)
            {
                unionSet(parent, s1, s2, rank);
            }
            else {
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    cout<<g.containCycle()<<endl;
    return 0;
}