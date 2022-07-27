#include<iostream>
using namespace std;

void recoverArray(int input[], int n, int output[])
{
    int left, right;
    if(n%2 !=0)
    {
        int mid = n/2;
        output[mid] = input[0];
        left = mid - 1;
        right = mid + 1;
    }else{
        left = n/2 - 1;
        right = n/2;
    }
    int i=1;
    while(i< n)
    {
        output[left] = input[i];
        left--;
        i++;
        output[right] = input[i];
        i++;
    }
}

int main()
{
    int input[100];
    int output[100];
    int n;
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    recoverArray(input, n, output);
}