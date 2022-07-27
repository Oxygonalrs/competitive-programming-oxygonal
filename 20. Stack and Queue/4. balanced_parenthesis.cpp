#include<iostream>
using namespace std;
#include<stack>

int main()
{
    string p;
    cin>>p;
    stack<char> s;
    bool flag = false;
    for(int i=0; i<p.size(); i++)
    {
        if(p[i]=='{' || p[i] == '[' || p[i] == '(')
        {
            s.push(p[i]);
        }
        if(p[i]=='}')
        {
            if(s.top() == '{')
                s.pop();
            else
            {
                flag = true;
                break;
            }
                
        }
        if(p[i]==']')
        {
            if(s.top() == '[')
                s.pop();
            else
            {
                flag = true;
                break;
            }
        }
        if(p[i]==')')
        {
            if(s.top() == '(')
                s.pop();
            else
            {
                flag = true;
                break;
            }
        }
    }
    if(flag == true)
        cout<<"Not Balanced"<<endl;
    else if(s.empty() != true)
        cout<<"Not Balanced"<<endl;
    else
        cout<<"Balanced"<<endl;
    
    return 0;
}