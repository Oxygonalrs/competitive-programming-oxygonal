#include<iostream>
using namespace std;
#include "5. queue.h"

int main()
{
    queue<char> q;
    q.push(65);
    q.push(66);
    q.push(67);
    q.push(68);
    q.push(69);
    q.push(40);

   

    // cout<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.empty()<<endl;
}