#include<iostream>
using namespace std;

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

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    // Complete Overlap
    if(ss>=qs and se<=qe)
    {
        return tree[index];
    }
    // No overlap
    if(qe<ss || qs>se) return INT_MAX;

    //Partial Overlap
    int mid = (ss + se)/2;
    int left = query(tree, ss, mid, qs,qe, 2*index);
    int right = query(tree, mid+1, se, qs,qe, 2*index+1);

    return min(left, right);
}

void update(int *tree, int ss, int se, int i, int increment, int index)
{
    //Case where the I is out of bounds
    if(i > se || i < ss)
    {
        return;
    }

    if(ss == se)
    {
        tree[index] += increment;
        return;
    }

    //otherwise
    int mid = (ss+se)/2;
    update(tree, ss, mid, i, increment, 2*index);
    update(tree, mid+1, se, i, increment, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}  

void rangeUpdate(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    //Out of Bounds
    if(l > se || r < ss)
    {
        return ;
    }

    if(ss == se)
    {
        tree[index] += inc;
        return ;
    }

    // Recursive Case
    int mid = (ss+se)/2;
    rangeUpdate(tree, ss, mid, l, r,inc, 2*index);
    rangeUpdate(tree, mid + 1, se, l, r,inc, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}

// Lazy Propagation in Segment Trees
int lazy[10000] = {0};
void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    // Before going down resolve the value if it exists
    if(lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if(ss != se)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }


    // Base Case
    if(ss > r or l > se)
    {
        return;
    }

    // another case
    if(ss >= l && se <= r)
    {
        tree[index] += inc;

        if(ss != se)
        {
            lazy[2*index] += inc;
            lazy[2*index + 1] += inc;
        }
        return;
    }
    
    // recursive case
    int mid = (ss+se)/2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2*index);
    updateRangeLazy(tree, mid + 1, se, l, r, inc, 2*index+1);
    tree[index] = min(tree[2* index], tree[2*index + 1]);

}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index)
{
    // Before going down resolve the value if it exists
    if(lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if(ss != se)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(ss > qe or se < qs)
    {
        return INT_MAX;
    }

    if(ss >= qs and se <= qe)
    {
        return tree[index];
    }

    int mid = (ss+se)/2;
    int left = queryLazy(tree, ss, mid, qs, qe, 2*index);
    int right = queryLazy(tree, mid+1, se, qs, qe, 2*index + 1);

    return min(left, right);
}


int main()
{
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a)/sizeof(int);

    int *tree = new int[4*n + 1];
    buildTree(a, 0, n-1, tree, 1);
    // for(int i=1; i<=13; i++)
    // {
    //     cout<<tree[i]<<" ";
    // }

    // update(tree, 0, n-1, 3, 10, 1);
    // rangeUpdate(tree, 0, n-1, 1, 5, 10, 1);

    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int l, r;
    //     cin>>l>>r;
    //     cout<<query(tree, 0, n-1, l, r, 1)<<endl;
    // }
    
    updateRangeLazy(tree, 0, n-1, 0, 2, 10, 1);
    updateRangeLazy(tree, 0, n-1, 0, 4, 10, 1);

    cout<<"Q1 1-1 "<<queryLazy(tree, 0, n-1, 1, 1, 1) << endl;
    updateRangeLazy(tree, 0, n-1, 3, 4, 10, 1);
    cout<<"Q1 3-5 "<<queryLazy(tree, 0, n-1, 3, 5, 1) << endl;
    
    
}