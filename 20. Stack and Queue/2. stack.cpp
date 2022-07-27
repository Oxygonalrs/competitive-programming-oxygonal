#include<iostream>
using namespace std;
#include "1. Stack.h"

int main()
{
    stack<char> s;
    s.push(70);
    s.push(69);
    s.push(68);
    s.push(67);
    s.push(66);
    s.push(65);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl; 

    //pair STL
    // Pair<int, int> p;
    // p.setX(5);
    // p.setY(5);
    // cout<<p.getX()<<" "<<p.getY()<<endl;
    // Pair<Pair<int,int>,int> p1;
    // Pair<int, int> p2;
    // p2.setX(5);
    // p2.setY(6);

    // p1.setX(p2);
    // p1.setY(7);

    // cout<<p1.getX().getX()<<" ";
    // cout<<p1.getX().getY()<<" ";
    // cout<<p1.getY()<<endl;
}