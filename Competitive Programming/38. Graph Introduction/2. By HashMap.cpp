#include<iostream>
#include<list>
#include<map>
#include<unordered_map>
using namespace std;

class Graph{
    int vertices;
    // list<int>* neighbours;
    map<string, list<pair<string, int>>> neighbours;
    // unordered_map<string, list<pair<string, int>>> neighbours;
    public:
    void addEdge(string A, string B, bool bid, int weight)
    {
        neighbours[A].push_back(make_pair(B, weight));
        if(bid)
        {
            neighbours[B].push_back(make_pair(A,weight));
        }
    }
    void print()
    {
        for(auto i : neighbours)
        {
            cout<<i.first<<" -> ";
            for(auto j : i.second)
            {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "B", true, 30);
    g.addEdge("B", "D", true, 40);
    g.addEdge("C", "D", true, 80);
    g.addEdge("D", "B", true, 50);
    g.addEdge("A", "D", false, 30);
    g.print();
    return 0;
}