#include<iostream>
#include<unordered_map>
using namespace std;

//Problem : To find a word exist or not 
//1) Linearly Traverse
//2) Hashmap
//3) Prefix Tree -> Trie
//Because words have same prefix

//Useful Application -> To save mobile No
//It is better for less than 1000, Use HashMap.

class Node{
    public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie{
    Node* root;
    public:
    int count;
    public:
    Trie()
    {
        count = 0;
        root = new Node('\0');
    }
    void insert(char *w)
    {
        Node* temp = root;
        for(int i=0; w[i]!='\0'; i++)
        {
            char ch = w[i];
            if(temp->children.count(ch) > 0)
            {
                temp = temp->children[ch];
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                count++;
            }
        }
        temp->terminal = true;
    }
    bool find(char *w)
    {
        Node* temp = root;
        for(int i=0; w[i]!='\0'; i++)
        {
            char ch = w[i];
            if(temp->children.count(ch) == 0)
            {
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        if(temp->terminal == true)  
            return true;
        return false;
    }
};

int main()
{
    Trie t;
    char words[5][10] = {"a", "hello", "not", "news", "apple"};
    char w[10];
    cin>>w;
    for(int i=0; i<5; i++)
    {
        t.insert(words[i]);
    }
    // cout<<t.count<<endl;
    if(t.find(w))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}