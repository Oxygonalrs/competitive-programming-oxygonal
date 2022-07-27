#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> a;
    vector<int> b(5, 10);  //five innt with value 10
    vector<int> c(b.begin(), b.end());
    vector<int> d({1, 2, 3, 4});
    vector<int> e(b);
    vector<int> f = d;
    cout<<a.size()<<endl;
    cout<<b.size()<<endl;
    cout<<c.size()<<endl;
    cout<<d.size()<<endl;
    cout<<e.size()<<endl;
    cout<<f.size()<<endl;
    cout<<f.max_size()<<endl;
    
    f.insert(f.begin() + 3, 100);
    f.insert(f.begin() + 3, 4, 100); //Insert 4 100 from +3 index
    f.erase(f.begin(), f.end());
    f.resize(5);
    f.clear(); //remove all elements
    cout<<endl<<d.front();
    cout<<endl<<d.back();
    f.reserve(100);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {

    } 
    return 0;
}