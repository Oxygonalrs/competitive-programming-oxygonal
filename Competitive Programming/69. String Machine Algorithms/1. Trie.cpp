#include<bits/stdc++.h>
using namespace std;

/*

String Matching Algorithm

String searching using Trie
Rabin-Karp Algorithm (Rolling Hash)
KNUTH-MORRIS-PRATT (Prefix-function)
Z - Function
Manachar's Algorithm

*/

struct trie
{
    trie* nxt[26];
    // bool ended;
    trie(){
        for(int i=0; i<26; i++)
        {
            nxt[i] = NULL;
        }
        // ended = false;
    }
};

trie *root; 

void insert(string s)
{
    trie* cur = root;
    for(int i=0; i<s.size(); i++)
    {
        if(cur->nxt[s[i]-'a'] == NULL)
        {
            cur->nxt[s[i]-'a'] = new trie();
        }
        cur = cur->nxt[s[i]-'a'];
    }
    // cur->ended = true;
}

bool search(string s)
{
    trie* cur = root;
    for(int i=0; i<s.size(); i++)
    {
        if(cur->nxt[s[i]-'a'] == NULL)
        {
            return false;
        }
        cur = cur->nxt[s[i]-'a'];
    }
    return true; 
    // return cur->ended;
}

int main()
{
    root = new trie();
    // insert("apaar");
    // insert("vishal");
    // insert("kamal");
    // insert("rahul");
    // insert("kartik");
    // insert("saurabh");

    // if(search("apaari"))
    // {
    //     cout<<"Found"<<endl;
    // }
    // else{
    //     cout<<"Not Found"<<endl;
    // }
    string text = "abaacadbacad";
    string pat = "aaca";

    int n = text.size();
    for(int i=0; i<n; i++)
    {
        insert(text.substr(i));
    }
    if(search(pat))
    {
        cout<<"OYEsss";
    }
}