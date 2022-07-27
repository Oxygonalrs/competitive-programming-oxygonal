//15, 12, 16, 2, 1, 0, 7, 8
#include<iostream>
#include<stack>
using namespace std;

void nextMinimumElement(int *a, int n)
{
    stack<int> s;
    int i=0;
    while(i<n)
    {
        if(s.empty())
        {
            s.push(a[i]);
            i++;
        }
        else if(s.top() < a[i])
        {
            cout<<s.top()<<" -> "<<a[i]<<endl;
            s.pop();
        }
        else
        {
            s.push(a[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" -> -1"<<endl;
        s.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    nextMinimumElement(a,n);
}