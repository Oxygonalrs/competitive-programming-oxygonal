#include<iostream>
using namespace std;
#include<stack>
//incomplete COde
int main()
{
    int ans = 0;
    string s;
    cin>>s;
    if(s.length()%2 != 0) return -1;
    cout<<"SIZE1 "<<s.length()<<endl;
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        cout<<" I "<<i<<endl;
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else if(s[i] == '}' && st.top() == '{')
        {    
            if(st.top() == '{')
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        else
        { 
            st.push(s[i]);
        }
    }
    cout<<"SIZE"<<st.size()<<endl;
    while(!st.empty())
    {
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        if(c1 == c2) ans++;
        else ans += 2;
    }
    cout<<ans;
}