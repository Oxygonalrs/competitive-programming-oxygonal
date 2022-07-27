#include<iostream>
#include<list>
using namespace std;

// Disjoint Union Set (DSU) / Union - Find 

class Graph{
    int v;
    list<pair<int, int>> l;

    public:
    Graph(int v)
    {
        this->v = v;
    }

    void addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    // FInd
    int findSet(int i, int parent[])
    {
        if(parent[i] == -1) return i;
        // return findSet(parent[i], parent); 
        
        //Path compression
        return parent[i] = findSet(parent[i], parent); 
    }

    void unionSet(int x, int y, int parent[], int rank[])
    {
        // int s1 = findSet(x, parent);
        // int s2 = findSet(y, parent);
        // if(s1 != s2) parent[s1] = s2;

        if(x != y)
        {
            if(rank[x] < rank[y])
            {
                parent[x] = y;
                rank[y] += rank[x];
            }    
            else 
            {
                parent[y] = x;
                rank[x] += rank[y];
            }    
        } 
    }

    bool containCycle(){
        int *parent = new int[v];
        int *rank = new int[v];
        for(int i=0; i<v; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for(auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2) unionSet(s1, s2, parent, rank);
            else return true;
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
    g.addEdge(3, 4);
    g.addEdge(0, 4);
    cout<<g.containCycle()<<endl;
    return 0;
}