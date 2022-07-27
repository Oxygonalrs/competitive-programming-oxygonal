#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/BUSYMAN/


bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int t, n, s, e;
    cin>>t;
    while(t--)
    {
        vector<pair<int, int>> p;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>s>>e;
            p.push_back(make_pair(s,e));
        }
        sort(p.begin(), p.end(), compare);
        int res = 1;
        int fin = p[0].second;

        for(int i=1; i<n; i++)
        {
            if(p[i].first >= fin)
            {
                fin = p[i].second;
                res++;
            }
        }
        cout<<res<<endl;
        p.clear();
    }
}