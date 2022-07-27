#include<bits/stdc++.h>
using namespace std;

struct trie{
    trie* next[26];
    bool ended;
    trie()
    {
        for(int i=0; i<26; i++) next[i] = NULL;
        ended = false;
    }
};
trie* root;

void insert(string s)
{
    trie *cur = root;
    for(int i=0; i<s.size(); i++)
    {
        if(cur->next[s[i]-'a'] == NULL)
        {
            cur->next[s[i]-'a'] = new trie();
        }
        cur = cur->next[s[i]-'a'];
    }
    cur->ended = true;
}

bool in_trie(string s)
{
    trie *cur = root;
    for(int i=0; i<s.size(); i++)
    {
        if(cur->next[s[i]-'a'] == NULL)
        {
            return false;
        }
        cur = cur->next[s[i]-'a'];
    }
    return cur->ended;
}

int main()
{
    root = new trie();
    insert("apaar");
    insert("vishal");
    insert("kamal");
    insert("rahul");
    insert("kartik");
    insert("saurabh");
    if(in_trie("apaar"))
    {
        cout<<"Yes Found"<<endl;
    }
    else cout<<"Not FOunt"<<endl;
}