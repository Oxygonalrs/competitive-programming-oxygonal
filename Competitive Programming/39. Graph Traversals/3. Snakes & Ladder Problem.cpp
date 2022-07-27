

/*

Minimum Number of Dice Throws Required
to reach the destination 36 starting from
the source. 
Find the shortest path as well

s = snakes and l = ladder
12 34
4 17

and l = ladder
2 15
18 29

6*6 -> grid

It is unweighted Graph

*/

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
    void SSSP(T start, T dest)
    {
        map<T, int> dist;
        map<T, T> parent; 
        queue<T> q;
        for(auto node_pair : neighbours)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(start);
        dist[start] = 0;
        parent[start] = start;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(int nbr : neighbours[node])
            {
                if(dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
        T temp = dest;
        while(temp != start)
        {
            cout<<temp<<"<-";
            temp = parent[temp];
        }
        cout<<start<<endl;
        cout<<dist[dest]<<endl;
    }
};


int main()
{
    int board[50] = {0};
    //Snakes and Ladders
    board[2] = 13; //15 - 2
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;
    for(int i=0; i<=36; i++)
    {
        for(int dice = 1; dice <=6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if(j<=36)
            {
                g.addEdge(i,j);
            }
        }
    }
    g.addEdge(36, 36);
    g.SSSP(0, 36);
}

