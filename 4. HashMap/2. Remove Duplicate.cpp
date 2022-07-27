#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> removeDuplicate(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i=0; i<size; i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

//O(mlogm + nlogn + (m+n)
vector<int> arrayIntersection(int *a, int *b, int m, int n)
{   
    sort(a, a+m);
    sort(b, b+n);
    int i=0, j=0;
    vector<int> v;

    while(i<m && j<n)
    {
        if(a[i] == b[j])
        {
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
        else
            j++;
    }
    return v;
}

void ArrayIntersection(int *a, int *b, int m, int n)
{
    unordered_map<int, int> ourMap;
    int i=0;
    for(i = 0; i<m; i++)
    {
        ourMap[a[i]]++;
    }
    for(i=0; i<n; i++)
    {
        if(ourMap.count((b[i])) > 0)
        {
            cout<<b[i]<<endl;
            ourMap[b[i]]--;
        }
        if(ourMap.count((b[i])) == 0)
        {
            ourMap.erase(b[i]);
        }
    }
}

void printPair(int *arr, int size)
{
	unordered_map<int, int> ourMap;
	for(int i=0; i<size; i++){
		if(ourMap.count(-1*arr[i]) > 0 && ourMap[-1*arr[i]] != 0)
		{
			ourMap[-1*arr[i]]--;
			cout<<arr[i]<<" "<<-1*arr[i]<<endl;
		}
        else{
            ourMap[arr[i]]++;
        }
	}
}


int main()
{
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0; i<n; i++)
    //     cin>>a[i];

    // vector<int> v = removeDuplicate(a, n);
    // for(int i: v)
    //     cout<<i<<" ";

    // int b[] = {1, 2, 2, 6, 8, 9};
    // int m1 = 6, n1 =5;
    // int c[] = {2, 3, 6, 8, 9};
    // // vector<int> v1 = arrayIntersection(b,c,m1,n1);
    // // for(int i: v1)
    // //     cout<<i<<" ";

    // ArrayIntersection(b,c,m1,n1);

    //Pair to Zero
    int arr[] = {-2, 2, 6, -2, 2, -6, 3};
	printPair(arr, 7);
    cout<<"end";

    return 0;
}