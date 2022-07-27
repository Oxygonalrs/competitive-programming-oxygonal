#include<iostream>
using namespace std;

void RecoverArray(int input[], int output[], int n)
{
    int left ,right;
    int i=0;
    if(n%2 != 0)
    {
        int mid = n/2;
        output[mid] = input[0];
        left = mid -1;
        right = mid +1;
        i++;
    }
    else{
        int mid = n/2;
        left = mid -1;
        right = mid;
    }
    
    while(i<n)
    {
        output[left] = input[i];
        left--;
        i++;
        output[right] = input[i];
        right++;
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    int input[n];
    int output[n];
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    RecoverArray(input, output, n);
    for(int i=0; i<n; i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}