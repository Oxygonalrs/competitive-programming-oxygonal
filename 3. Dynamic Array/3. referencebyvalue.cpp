#include<iostream>
using namespace std;

void increment(int& n)
{
    n++;
}

//Bad Practise
int& fun(int n)
{
    int a = n;
    return a;
}

int* fun2()
{
    int i=10;
    return &i;
}

int main()
{
    int i = 10;
    int &j = i;

    int &k2 = fun(i);
    int *k1 = fun2();

    increment(i);
    cout<<i<<endl;
    i++;
    cout<<j<<endl;

    int k = 100;
    j=k;
    cout<<i<<endl;
    return 0;
}