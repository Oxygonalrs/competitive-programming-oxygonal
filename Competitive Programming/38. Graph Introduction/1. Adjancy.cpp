#include<iostream>
#include<list>
using namespace std;

class Graph{
    int vertices;
    list<int> *neighbours;
    public:
    Graph(int vertices){
        this->vertices = vertices;
        neighbours = new list<int>[vertices];
    }
    void addEdge(int x, int y)
    {
        neighbours[x].push_back(y);
        neighbours[y].push_back(x);
    }
    void print()
    {
        for(int i=0; i<vertices; i++)
        {
            cout<<"Vertext "<<i<<" -> ";
            for(int x : neighbours[i])
            {
                cout<<" "<<x;
            }
            cout<<endl;
        }
    }
};

int main()
{

    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.print();
    return 0;
}