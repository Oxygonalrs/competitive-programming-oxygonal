class TrieNode{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;
    public:
    int count = 0;
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(TrieNode *root, string word)
    {
        if(word.size() == 0) 
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL)
        {
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            count++;
        }

        insert(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insert(root, word);
    }

    bool search(TrieNode* root, string word) 
    {
        if(word.size() == 0)
        {
            if(root->isTerminal == true)
                return true;
            return false;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        bool ans = false;
        if(root->children[index] != NULL && root->children[index]->data == word[0])
        {
            child = root -> children[index];
            ans = search(child, word.substr(1));
        }
        return ans;
    }

    bool searchWord(string word)
    {
        return search(root, word);
    }

    void remove(TrieNode *root,string word)
    {
        if(word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            return;
        }
        remove(child, word.substr(1));
        if(child->isTerminal == false)
        {
            for(int i=0; i<26; i++)
            {
                if(child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    
    void removeWord(string word)
    {
        remove(root, word);
    }
};