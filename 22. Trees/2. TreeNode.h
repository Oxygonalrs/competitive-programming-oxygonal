#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    // vector<TreeNode*> children;  same

    TreeNode(int data)
    {
        this->data = data;
    }

    //2nd way
    // ~TreeNode(){
    //     for(int i=0; i<children.size; i++)
    //     {
    //         delete children[i];
    //     }
    // }
};