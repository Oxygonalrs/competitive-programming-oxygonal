#include<iostream>
using namespace std;
#include <queue>

// DFS
void print(int ** edges, int n, int sv, bool *visited)
{
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i=0; i<n; i++)
    {
        if(i == sv) continue;
        if(edges[sv][i] == 1)
        {
            if(visited[i]) continue;
            print(edges, n, i, visited);
        }   
    }
}

//BFS 
void printBFS(int ** edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty())
    {
        int ans = q.front();
        q.pop();
        cout<<ans<<" ";
        for(int i=0; i<n; i++)
        {
            if(i == ans) continue;
            if(edges[ans][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            } 
        }
    }
    cout<<endl;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            print(edges, n, i, visited);
        }
    }
    delete [] visited;
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

    
    DFS(edges, n);
    cout<<"\nBFS"<<endl;
    BFS(edges, n);

    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    cout<<"Done "<<endl;
    return 0;
}