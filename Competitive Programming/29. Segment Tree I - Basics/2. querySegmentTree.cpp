#include<iostream>
#include<climits>
using namespace std;

//Complexity
//Build -> O(N)
//Query -> O(logN)
//Point Update -> O(logN)
//Range Update -> O(logN) //Worst Case

void buildTree(int* a, int s, int e, int *tree, int index)
{
    //Base case
    if(s == e)
    {
        tree[index] = a[s];
        return;
    }

    //Recursive Case
    int mid = (s+e)/2;
    buildTree(a, s, mid, tree, 2*index);
    buildTree(a, mid + 1, e, tree, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}

//1. Partial Overlap
//2. Complete overlap
//3. No overlap

int query(int* tree, int ss, int se, int qs, int qe, int index)
{
    //Completer Overlap
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }
    //No overlap
    if(qe<ss || qs>se)
    {
        return INT_MAX;
    }
    //partial Overlap
    int mid = (ss+se)/2;
    int left = query(tree, ss, mid, qs, qe, 2*index);
    int right = query(tree, mid + 1, se, qs, qe, 2*index + 1);
    return min(left, right);
}

//Point Update
void update(int *tree, int ss, int se, int i, int increment, int index)
{
    //Case where the I is out of bounds
    if(i>se || i<ss) return;

    //leaf node
    if(ss == se)
    {
        tree[index] += increment;
        return;
    }

    //otherwise
    int mid = (ss + se)/2;
    update(tree, ss, mid, i, increment, 2*index);
    update(tree, mid + 1, se, i, increment, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}

//Range Update
void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    //Out of Bounds
    if(l>se || r < ss)
    {
        return;
    }
    //leaf Node
    if(ss == se)
    {
        tree[index] += inc;
        return;
    }
    ///recursive case
    int mid = (ss + se)/2;
    updateRange(tree, ss, mid, l, r, inc, 2*index);
    updateRange(tree, mid + 1, se, l, r, inc, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}

int main()
{
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a)/sizeof(int);
    int *tree = new int[4*n + 1];
    buildTree(a, 0, n-1, tree, 1);
    // update(tree, 0, n-1, 3, 10, 1);
    updateRange(tree, 0, n-1, 3, 5, 10, 1);
    int q; 
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(tree, 0, n-1, l, r, 1)<<endl;
    }
    // for(int i=1; i<=13; i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
}