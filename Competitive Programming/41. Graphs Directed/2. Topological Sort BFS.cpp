#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;

class Graph
{
    list<int> *l;
    int v;
    public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
    void topological_sort(){
        int *indegeree = new int[v];
        for(int i=0; i<v; i++)
        {
            indegeree[i] = 0;
        }
        for(auto p : l)
        {
            int x = p.first;
            for(auto y : p.second)
            {
                indegeree[y]++;
            }
        }
    }
};

int main()
{

}