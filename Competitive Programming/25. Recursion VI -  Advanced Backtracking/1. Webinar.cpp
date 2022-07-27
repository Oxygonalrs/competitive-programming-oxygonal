/*
Topic : Backtracking++
How to use bitmasks during backtracking!

Questions
1) N - Queen Problem
- print/count 1 config
- print/count all config

Approaches
1) Naive Backtracking approach - O(N^N)
2) 
3) 
*/

// Stop at 30.00 min

#include<iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    // You can check for col
    for(int row = 0; row<i; row++)
    {
        if(board[row][j] == 1) return false;
    }

    // You can check for Left Diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >=0)
    {
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }
    x = i;
    y = j;
    while(x >= 0 && y < n)
    {
        if(board[x][y] == 1) return false;
        x--;
        y++;
    }

    // The Position is now safe
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    // Base case
    if(i == n) 
    {
        //You have successfully place N queen
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 1) cout<<" Q ";
                else cout<<" _ ";
            }
            cout<<endl;
        }
        cout<<endl;

        // Return true for only one solution
        // Return false for all configuration
        return false;
    }

    // Recursion Case
    // Try to place the queen in the current row and cell on the remaining part
    for(int j=0; j<n; j++)
    {
        // I have to check if i, j th position is safe or not
        if(isSafe(board, i, j, n))
        {
            // Place the Queen - i,j is right position
            board[i][j] = 1;
            bool nextQueen = solveNQueen(board, i+1, n);
            if(nextQueen)
            {
                return true;
            }

            // BackTrack
            board[i][j] = 0;
        }
    }

    // You have tried for all position but couldn't place a queen
    return false;
}

int main()
{
    int n;
    cin>>n;
    int board[10][10] = {0};
    cout<<"Hello"<<endl;
    solveNQueen(board, 0, n);
    return 0;
}