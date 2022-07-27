#include<iostream>
using namespace std;

int alphaCode(int* a, int size)
{
    if(size == 1 || size == 0) return 1;
    int output = 0;
    output = alphaCode(a, size-1);
    if((a[size-2]*10+a[size-1])<=26)
    {
        cout<<"Size: "<<size<<endl;
        output = output + alphaCode(a, size-2);
    }
    return output;
}

// int alphaCodeR(int* n, int size, int *arr)
// {
//     if(size == 1 || size == 0) return 1;
//     if(arr[size] > 0) return arr[size];
//     int output = alphaCode(n, size -1);
//     if((n[size-2]*10 + n[size-1]) <= 26)
//         output += alphaCode(n, size-2);
//     arr[size] = output;
//     return output;
// }

int main()
{
    int n;
    cin>>n;
    int a[n];
    
    //If we assign two array one by one that give bug

    // int arr[n+1] = {0};
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Recursion: "<<alphaCode(a,n)<<endl;
    // cout<<"Recursion: "<<alphaCodeR(a,n, arr)<<endl;
    return 0;
}