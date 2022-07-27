#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/BAISED/
//It can do by using sort function as well;
//That will take O(NlogN)
int abs(int i, int j)
{
    return i-j>=0 ? i-j : j-i;
}
int main()
{
    int arr[100000] = {0};
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(arr, 0, sizeof arr);
        string name;
        int n, rank;
        cin>>n;

        // counting sort
        for(int i=0 ; i<n; i++)
        {
            cin>>name>>rank;
            arr[rank]++;
        }
        //Greedy Approach
        int actual_rank = 1;
        int sum = 0;
        for(int i=1; i<=n; i++)
        {
            while(arr[i])
            {
                sum+= abs(actual_rank, i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

Node* kthNodeFromEnd(Node* head, int k)
{
    if(head == NULL) reutrn NULL;
  
} 