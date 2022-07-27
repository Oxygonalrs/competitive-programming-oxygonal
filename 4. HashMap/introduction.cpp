#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;
    pair<string, int> p("abc",1);
    ourMap.insert(p);
    // ourMap.insert("def",2);
    //GIving Error
    ourMap["def"] = 2;

    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("def")<<endl;
    cout<<ourMap.size()<<endl;
    // cout<<ourMap.at("ghi")<<endl;
    cout<<ourMap["ghi"]<<endl;
    //It will check if not exist then it created and enter 0

    cout<<ourMap.size()<<endl;

    //It count key and not value
    if(ourMap.count("Ghi") > 0)
        cout<<"It is Exist"<<endl;
    else
        cout<<"It is not Exist"<<endl;

    ourMap.erase("ghi");
    cout<<ourMap.size()<<endl;


    // int a[256] = {0};
    // for(int i=0; i<256; i++)
    //     cout<<i+1<<"  "<<a[i]<<endl;
    // return 0;
    //Make Hashmap By using BST

    // map-> BST ->log(n)
    // unordered_map -> HashTable -> O(1)
}