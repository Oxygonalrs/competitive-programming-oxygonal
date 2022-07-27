#include<iostream>
using namespace std;
#include<vector>


int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //Try this your Own
    // vector<int> *vp = new vector<int>();
    // vp->push_back(10);
    // vp->push_back(20);
    // vp->push_back(30);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    cout<<v.size()<<endl;
    // cout<<v.at(6)<<endl;

    //Don't use [] for insertion
    
    v.pop_back();
    cout<<v.capacity()<<endl;

    for(auto i : v)
        cout<<i<<endl;
    
    return 0;
}