#include<iostream>
#include<set>
using namespace std;

int main()
{
    //In set or multiset, values once inserted can't be modified
    //Underlying DS is BST

    // set<int> s{1,4,5,6,9,2};
    // for(auto i : s)
    // {
    //     cout<<i<<" ";
    // }
    
    multiset<int> s{1,2,4,5,8,9, 9, 7, 9, 9,3,2,4,6};
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<s.count(10)<<endl;

    //get all element which are equal to 2
    typedef multiset<int> :: iterator It;
    pair<It, It> p = s.equal_range(9);
    for(auto it = p.first; it != p.second; it++)
    {
        cout<<*it<<endl;
    }
    // >= to <
    for(auto it = s.lower_bound(1); it != s.upper_bound(7); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}