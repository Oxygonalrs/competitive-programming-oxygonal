#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int> v;
    vector<int> * vp = new vector<int>();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v.at(0)<<endl; 
    v.pop_back();
}