#include<iostream>
#include <vector>
using namespace std;
#include "1. BinaryTreeNode.h"
#include<queue>
// #include "./18. Linked List/0. class.h"
#include "../18. Linked List\0. class.h"

void print(BinaryTreeNode<int>* root)
{
    if(root == NULL) return;
    // cout<<root->data<<endl;
    // print(root->left);
    // print(root->right);

    cout<<root->data<<" : ";
    if(root->left != NULL)
    {
        cout<<"L "<<root->left->data;
    }
    if(root->right != NULL)
    {
        cout<<", R "<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cin>>rootData;
    if(rootData == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int>* takeInputLevel()
{
    int rootData;
    cin>>rootData;
    queue<BinaryTreeNode<int>*> pendingNodes;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        cout<<"Enter Left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter Right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevel(BinaryTreeNode<int>* root)
{
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        if(front->left != NULL)
        {
            cout<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->left != NULL)
        {
            cout<<", "<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

//No of Nodes
int numberOfNode(BinaryTreeNode<int>* root)
{
    if(root == NULL) return 0;
    int leftNodes = numberOfNode(root->left);
    int rightNodes = numberOfNode(root->right);
    return leftNodes + rightNodes + 1;
}

void preOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL) return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;
}

void inOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right); 
}

int linearSearch(int a[], int s,int n, int x)
{
    for(int i=s; i<=n; i++)
    {
        if(a[i] == x)
            return i;
    }
    return -1;
}


//Incomplete

// BinaryTreeNode<int>* generateTreeFromPreAndIn(int pre[], int in[], int startIn, int endIn, int startPre, int endPre)
// {
//     if(startIn > endIn) return NULL;
//     int rootData = pre[startPre];
//     int lPreS = startPre + 1;
//     int lPreE = ;
//     int lInS = startIn;
//     int lInE linearSearch(in, startIn, endIn, rootData);
//     int rPreS;
//     int rPreE = endPre;
//     int rInS;
//     int rInE = endIn;
//     BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
//     root->left = generateTreeFromPreAndIn(pre, in, lInS, lInE, lPreS, lPreE); 
//     root->right = generateTreeFromPreAndIn(pre, in, rInS, rInE, rPreS, rPreE); 
//     return root;
// }

int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return 0;
    return 1+max(height(root->left), height(root->right));
}

//Order of n*h 
// int diameterOfNode(BinaryTreeNode<int>* root)
// {
//     if(root == NULL) return 0;

//     int option1 = height(root->left) + height(root->right);
//     int option2 = diameterOfNode(root->left);
//     int option3 = diameterOfNode(root->right);

//     return max(option1, max(option2, option3));
// }

//Better Apparoach
pair<int, int> diameterOfNode(BinaryTreeNode<int>* root)
{
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    } 

    pair<int, int> leftAns = diameterOfNode(root->left);
    pair<int, int> rightAns = diameterOfNode(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh+rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

//Incomplete
vector<Node*> LinkedListLevelWise(BinaryTreeNode<int> * root)
{
    vector<Node*> v;
    if(root == NULL)
        return v;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node* head = NULL;
    Node* tail = NULL;
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        while(front != NULL)
        {  
            if(front->left != NULL)
                pendingNodes.push(front->left);
            if(front->right != NULL)
                pendingNodes.push(front->right);
            if(head == NULL)
            {
                Node * temp = new Node(front->data);
                head = tail = temp;
            }
            else{
                Node* temp = new Node(front->data);
                tail->next = temp;
                tail = temp;
            }
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
        }
        pendingNodes.push(NULL);
        pendingNodes.pop();
        v.push_back(head);
        head = tail = NULL;
    }
    return v;   
}

int main()
{
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;
    // print(root);

    // 1 2 4 -1 -1 5  6 -1 -1 7 -1 -1 3 -1 8 -1 -1 
    BinaryTreeNode<int>* root = takeInput();
    // print(root);

    // 1 2 3 4 5 6 7 -1 - 1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTreeNode<int>* root = takeInputLevel();
    // print(root);
    printLevel(root);

    //No of Nodes
    // cout<<"No of Nodes : "<<numberOfNode(root)<<endl;
    // cout<<"PreOrder: ";preOrder(root);
    // cout<<"InOrder: ";inOrder(root);
    
    // int Pre[] = {1, 2, 4, 5, 8, 9, 3, 6, 7};
    // int In[] = {4, 2, 8, 5, 9, 1, 6, 3, 7};
    
    // BinaryTreeNode<int>* root = generateTreeFromPreAndIn(Pre, In, 0, 8, 0, 8);
    // cout<<"Print"<<endl;
    // print(root);
    
    // //Diameter of Node
    // pair<int,  int> p = diameterOfNode(root);
    // cout<<"Diameter : "<<p.second<<endl;
    // cout<<"Height : "<<p.first<<endl;

    //Linked List Level Wise
    
    vector<Node*> main = LinkedListLevelWise(root);
    cout<<main.size()<<" SIZE ";
    delete root;
    return 0;
}