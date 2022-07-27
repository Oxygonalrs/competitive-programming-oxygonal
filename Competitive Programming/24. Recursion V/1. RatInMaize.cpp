#include<iostream>
using namespace std;

bool ratInMaze(char grid[][10], int solution[][10], int n, int m, int i, int j)
{
    // Base case
    if(i == n && j == m)
    {
        solution[i-1][j-1] = 1;
        for(int i1=0; i1<n; i1++)
        {
            for(int j1=0; j1<m; j1++)
            {
                cout<<solution[i1][j1]<<" ";
            }
            cout<<endl;
        }
        cout<<"-------"<<endl;
        return true;
    }
    if(i>n || j>m)
    {
        return false;
    }
    if(grid[i-1][j-1] == 'X')
    {
        return false;
    }
    solution[i-1][j-1] = 1;

    // Recursion
    bool rightSuccess = ratInMaze(grid, solution, n, m, i, j+1);
    bool downSuccess = ratInMaze(grid, solution, n, m, i+1, j);
    
    // Backtracking
    solution[i-1][j-1] = 0;
    if(rightSuccess || downSuccess)
    {
        return true;
    }
    return false; 
}

int main()
{
    char grid[10][10] = {"0000", "00X0", "000X", "0X00"};
    int solution[10][10] = {0};
    ratInMaze(grid, solution, 4, 4, 1, 1);
}