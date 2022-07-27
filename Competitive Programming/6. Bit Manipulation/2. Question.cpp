#include<iostream>
using namespace std;

/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j.
Write a method to set all bits between i and j in N equal to M 
(e.g., M becomes a substring of N located at i and starting at j).

Example:
Input : N = 10000000000
M = 10101, i=2, j=6
Output : N = 10001010100
*/
int clearITOJBit(int n, int i, int j)
{
    int a = (~0)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    return n&mask;
}

int ReplaceBit(int n, int m, int i, int j)
{
    n = clearITOJBit(n, i, j);
    return n|(m<<i);
}
int main()
{
    int n = 15;
    int i = 1, j = 3;
    int m = 2;
    cout<<ReplaceBit(n,m,i,j);
}