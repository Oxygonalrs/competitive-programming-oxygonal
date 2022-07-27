#include<iostream>
using namespace std;
#include <stack>

int main()
{
    //Only difference in inbuild and our class is
    //that pop() return void in inbuilt and isEmpty == empty
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    cout<<"Done!"<<endl;
}