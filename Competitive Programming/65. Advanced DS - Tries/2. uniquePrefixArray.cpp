#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// words[] = ["cobra", "dog", "dove", "duck"];
// output[] = ["c", "dog", "dov", "du"]

class Node{
    public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    int count;
    Node(char d)
    {
        data = d;
        count = 1;
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
                temp->children[ch]->count++;
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
    vector<string> uniquePrefixArray(char input[][10], int n)
    {
        vector<string> finalAns;
        for(int j=0; j<n; j++)
        {
            string ans = "";
            for(int i=0; input[j][i] != '\0'; i++)
            {
                Node* temp = root;
                char ch = input[j][i];
                if(temp->children.count(ch) == 0)
                {
                    finalAns.push_back("");
                    break;
                }
                else{
                    if(temp->children[ch]->count == 1)
                    {
                        finalAns.push_back(ans);
                        break;
                    }
                    // ans+= temp->children[ch]->data;
                    temp = temp->children[ch];
                    ans += temp->children[ch]->data;

                }
            }
        }
        return finalAns;
    }
};

int main()
{
    Trie t;
    char words[][10] = {"cobra", "dog", "dove", "duck"};
    // char output[][10] = {-1, -1, -1, -1};
    // char words[5][10] = {"a", "hello", "not", "news", "apple"};
    // char w[10];
    // cin>>w;
    for(int i=0; i<4; i++)
    {
        t.insert(words[i]);
    }
    cout<<t.count<<endl;
    vector<string> ans = t.uniquePrefixArray(words, 4);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<"Hello"<<endl;
    // cout<<t.count<<endl;
    // if(t.find(w))
    // {
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }
}