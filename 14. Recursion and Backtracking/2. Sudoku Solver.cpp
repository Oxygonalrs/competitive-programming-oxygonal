#include<iostream>
using namespace std;

void sudoKuSolverHelper(int** input, int n, int** solution, int x, int y){
    if(x == n-1 && y == n-1)
    {
        
    }
}

void sudoKuSolver(int ** arr, int n)
{
    int** solution = new int*[n];
    for(int i=0; i<n; i++)
    {
        solution[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            solution[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    sudoKuSolver(arr, n);
    return 0;
}