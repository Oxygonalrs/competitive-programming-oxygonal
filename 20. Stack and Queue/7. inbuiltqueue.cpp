#include<iostream>
using namespace std;
#include<queue>

int main()
{
    queue<char> q;
    q.push(65);
    q.push(66);
    q.push(67);
    q.push(68);
    q.push(69);
    q.push(40);

   

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
}