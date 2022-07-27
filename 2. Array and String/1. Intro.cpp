#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    double hi;
    Node *next;
    int data;
    char mayur;
};

void text(int * a, int b[])
{
    cout<<a+1<<endl;
    cout<<*(a+50)<<endl;
    cout<<a[4]<<endl;
    cout<<b+1<<endl;
    cout<<*(b+50)<<endl;
    cout<<b[4]<<endl;
}
int main()
{
    // int n;
    // cin>>n;
    int a[] = {1, 2 , 4 ,5,6};
    text(a,a);
    // cout<<sizeof(a)<<endl;
    // cout<<sizeof(int)<<endl;
    // cout<<sizeof(double)<<endl;
    // cout<<sizeof(char)<<endl;
    // cout<<sizeof(Node)<<endl;

    // cout<<a+0<<endl;
    // cout<<a+1<<endl;
    // cout<<a+2<<endl;
    // cout<<a+3<<endl;
    // cout<<a+4<<endl;
    // cout<<a+5<<endl;
    return 0;
}