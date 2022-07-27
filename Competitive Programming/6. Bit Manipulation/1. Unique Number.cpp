#include<iostream>
#include<climits>
using namespace std;

bool isOdd(int n)
{
    return (n&1);
}

int getBit(int n, int i)
{
    int mask = (1<<i);
    int bit = n&mask > 0 ? 1 : 0;
    return bit;
}

int setBit(int n, int i)
{
    int mask = (1<<i);
    int bit = n|mask;
    return bit;
}

int clearBit(int n, int i)
{
    int mask = ~(1<<i);
    return n&mask;
}

int update(int n, int i, int j)
{
    n = clearBit(n, i);
    n = n|(j<<i);
    return n;
}

int clearIBit(int n, int i)
{
    //all ones
    int mask = (-1<<i);
    return n&mask;
}

int clearITOJBit(int n, int i, int j)
{
    int a = (~0)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    return n&mask;
}

int main()
{
    //Unique Number
    // int n;
    // cin>>n;
    // int no; 
    // int ans = 0;
    // for(int i=0; i<n; i++)
    // {
    //     cin>>no;
    //     ans = ans^no;
    // }
    // cout<<ans<<endl;
    // 7
    // 2 3 5 6 3 2 5

    // 3


    //Check Number is Odd or Even
    // int n = 5;
    // int n1 = 2;
    // cout<<isOdd(n1)<<endl;
 

    //Find ith bit
    // cout<<getBit(8, 2);


    //Set ith Bit
    // cout<<setBit(8,2);


    //Clear a bit at ith Position
    // cout<<clearBit(15, 3);

    //Update
    // cout<<update(8, 2, 1);

    //Clear a range
    // cout<<clearIBit(15, 3);

    
    //clear i to j
    cout<<clearITOJBit(31,1,3);
    cout<<endl;-
    int i = INT_MAX;
    cout<<i<<endl;
    i = i>>1;
    cout<<i<<endl;
    return 0;
}