#include <iostream>
using namespace std;
#include <unordered_map>
#include <map>
#include <vector>
int main()
{
    // unordered_map<string, int> ourmap;
    // ourmap["abc"] = 1;
    // ourmap["abc1"] = 2;
    // ourmap["abc2"] = 3;
    // ourmap["abc3"] = 4;
    // ourmap["abc4"] = 5;
    // ourmap["abc5"] = 6;
    // // unordered_map<string, int> :: iterator it = ourmap.begin();
    // unordered_map<string, int> :: iterator it;
    // it = ourmap.begin();
    // while(it != ourmap.end())
    // {
    //     cout<<"Key : "<<it->first<< ", Value : "<<it->second<<endl;
    //     it++;
    // }
    // unordered_map<string, int> :: iterator it2 = ourmap.find("abc");
    // ourmap.erase(it2->first);
    // ourmap.erase(it2, it2+4); //[)
    map<string, int> ourMap;
    // unordered_map<string, int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc1"] = 2;
    ourMap["abc2"] = 3;
    ourMap["abc3"] = 4;

    // unordered_map<string, int> :: iterator it;
    map<string, int> :: iterator it;
    it = ourMap.begin();

    for(it; it != ourMap.end(); it++)
    {
        cout<<it->first<<" -> "<<it->second<<endl;
    }
    cout<<endl;
    for(auto it1 : ourMap)
    {
        cout<<it1.first<<" -> "<<it1.second<<endl;
    }


    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // vector<int> :: iterator it1 = v.begin();
    // while(it1 != v.end())
    // {
    //     cout<<*it1<<endl;
    //     it1++;
    // }
    // return 0;
}