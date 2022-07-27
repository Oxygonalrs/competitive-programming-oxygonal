#include<bits/stdc++.h>
// #include<list>
using namespace std;

//List is doubly Linked list

int main()
{
    list<int> ls;
    list<int> l1{1,2,3,10};
    list<string> l2{"apple", "gauva","gauva", "mango", "banana"};
    l2.push_back("pineapple");
    l2.sort();
    l2.reverse();
    l2.erase(l2.begin());
    l2.remove("gauva");
    auto it = l2.begin();
    it++;
    // it = l2.begin()
    l2.insert(it++, "Kiwi");
    for(auto i : l2)
    {
        cout<<i<<" ";
    }
    //l2.begin() + 3  NOT WORK because memory is not linear
    ls.push_back(3);
    ls.push_back(4);
    ls.push_front(2);
    ls.push_front(1);

    return 0;
}