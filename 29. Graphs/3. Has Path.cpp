#include<iostream>
using namespace std;
#include <queue>
#include <vector>

// DFS
vector<int> print(int ** edges, int n, int sv, int end, bool *visited)
{
    visited[sv] = true;
    vector<int>  v;
    if(sv == end)
    {
        v.push_back(sv);
        return v;
    }
    for(int i=0; i<n; i++)
    {
        if(i == sv) continue;
        if(edges[sv][i] == 1)
        {
            if(visited[i]) continue;
            v = print(edges, n, i, end, visited);
            if(v.size() != 0)
            {
                v.push_back(sv);
                continue;
            }
        }   
        
    }
    return v;
}



int main()
{
    int n;
    int e;
    cin>>n>>e;
    int ** edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool * visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }

    vector<int> v = print(edges, n, 0, 3, visited);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" -> ";
    }

    delete [] visited;
    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    cout<<"Done "<<endl;
    return 0;
}