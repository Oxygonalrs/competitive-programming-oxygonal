#include<bits/stdc++.h>
using namespace std;
#include "2. TreeNode.h" 


void print(TreeNode<int>* root)
{   
    //This is Edge case and not a base case
    if(root == NULL) return;
    cout<<root->data<<" : ";
    for(int i=0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void printLevelWise(TreeNode<int>* root)
{
    if(root == NULL) return;
    queue<TreeNode<int>*> pendingQueue;
    // cout<<root->data<<endl;
    pendingQueue.push(root);

    while(!pendingQueue.empty())
    {
        TreeNode<int>* front = pendingQueue.front();
        cout<<front->data<<"->";
        pendingQueue.pop();
        for(int i=0; i<front->children.size(); i++)
        {
            pendingQueue.push(front->children[i]);
        }
    }
}

//By Recursive
TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter num of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLevel()
{
    queue<TreeNode<int>*> pendingNodes;
    int rootData;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0; i<numChild; i++)
        {
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int numNodes(TreeNode<int>* root)
{
    if(root == NULL) return 0;
    int ans = 1;
    for(int i=0; i<root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int heightNode(TreeNode<int>* root)
{
    if(root == NULL) return 0;
    int ans = 0;
    for(int i=0; i<root->children.size(); i++)
    {
        ans = max(ans, heightNode(root->children[i]));
    }
    return ans + 1;
}

//Depth of the Node
void depthNode(TreeNode<int>* root, int k)
{
    if(root == NULL) return;
    if(k==0) 
    {
        cout<<root->data<<" ";
        return;
    }
    for(int i=0; i<root->children.size(); i++)
    {
        depthNode(root->children[i], k-1);
    }

}

//Count Leaf
int countNode(TreeNode<int>* root)
{
    if(root == NULL) return 0;
    int ans = 0;
    for(int i=0; i<root->children.size();i++)
    {
        ans += countNode(root->children[i]);
    }
    if(root->children.size() == 0)
    {
        ans++;
    }
    return ans;
}

void preOrder(TreeNode<int>* root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int>* root)
{
    if(root == NULL) return;
    for(int i=0; i<root->children.size();i++)
    {
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int>* root)
{
    for(int i=0; i<root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

TreeNode<int>* findNextLargerElement(TreeNode<int>* root, int x)
{
    if(root == NULL) return NULL;
    TreeNode<int>* ans;
    ans = (root->data > x) ? root : NULL;
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int>* temp = findNextLargerElement(root->children[i], x);
        if(ans==NULL && temp ==NULL) continue;
        else if(ans == NULL && temp != NULL) ans = temp;
        else if(ans != NULL && temp != NULL) 
        {
            if(temp->data < ans->data && temp != NULL) ans = temp;
        }
    }

    return ans;
}

void replaceNodeWithDepth(TreeNode<int>* root, int k)
{
    if(root == NULL) return;
    root->data = k;
    for(int i=0; i<root->children.size(); i++)
    {
        replaceNodeWithDepth(root->children[i], k+1);
        root->children[i]->data = k+1;
    }
}

pair<TreeNode<int>*,int> sumMaximum(TreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<TreeNode<int>*,int> p;
        p.first = NULL;
        p.second = 0;
        return p;
    }
    int sum = root->data;
    TreeNode<int>* ans = root;
    for(int i=0; i<root->children.size(); i++) sum += root->children[i]->data;
    for(int i=0; i<root->children.size(); i++)
    {
        pair<TreeNode<int>*,int> p;
        p = sumMaximum(root->children[i]);
        if(sum < p.second && p.first != NULL)
        {
            sum = p.second;
            ans = p.first;
        }
    }
    pair<TreeNode<int>*,int> p;
    p.first = ans;
    p.second = sum;
    return p;
}

pair<int,int> secondMaximum(TreeNode<int>* root)
{
    if(root == NULL) {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    int Max = 0, sMax = 0;
    Max = root->data;
    sMax = Max;
    for(int i=0; i<root->children.size(); i++)
    {
        if(root->children[i]->data < Max)
        {
            int temp = root->children[i]->data;
            sMax = max(temp, sMax);
        }
        else {
            Max = root->children[i]->data;
        }
        pair<int,int> p = secondMaximum(root->children[i]);
        if(p.first > Max)
        {
            sMax = max(Max,p.second);
            Max = p.first;
        }
        else if(p.second > sMax)
        {   
            sMax = max(p.first, sMax);
        }
    }
    pair<int ,int> p;
    p.first = Max;
    p.second = sMax;
    return p;
}

int main()
{
    //Tree
    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    //     1
    // 3
    // 2 3 4
    // 2
    // 5 6
    // 0
    // 0
    // 0 0

    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    // TreeNode<int>* root = takeInput();
    // print(root);

    TreeNode<int>* root = takeInputLevel();
    print(root);
    // cout<<endl;
    // printLevelWise(root);cout<<endl;
    cout<<"Total Node: "<<numNodes(root)<<endl;
    cout<<"Total Height: "<<heightNode(root)<<endl;
    cout<<"Count Node: "<<countNode(root)<<endl;
    cout<<"Level: ";depthNode(root, 2);cout<<endl;
    
    // preOrder(root);cout<<endl;
    // postOrder(root);cout<<endl;
    
    //Deleting our tree
    // deleteTree(root);
    // cout<<"Delete Done"<<endl;
    
    //2nd way
    // delete root;


    //Assignments

    // TreeNode<int>* ans = findNextLargerElement(root, 10);
    // if(ans != NULL) cout<<"Find Larger Element Value: "<<ans->data<<endl;
    // else cout<<"No larger Element"<<endl;

    // replaceNodeWithDepth(root, 1);
    // printLevelWise(root);cout<<endl;

    // pair<TreeNode<int>*,int> p = sumMaximum(root);
    // cout<<"Node "<<p.first->data<<endl;
    // cout<<"Sum "<<p.second<<endl;
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    pair<int, int> p = secondMaximum(root);
    if(p.first != p.second) cout<<"Second Maximum : "<<p.first<<" "<<p.second<<endl;
    else cout<<"Not Second Maximum"<<endl; 
    return 0;
}   