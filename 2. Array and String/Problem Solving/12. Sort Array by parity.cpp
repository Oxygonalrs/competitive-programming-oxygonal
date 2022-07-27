#include<iostream>
using namespace std;

//Brute Force Approach
void sortArrayByParity(int *a, int n)
{
    int i = 0, j=n-1;
    while(i<j)
    {
        if(a[i]%2 == 0 && a[j]%2 != 0)
        {
            i++;
            j--;
        }
        else if(a[i]%2 == 0 && a[j]%2 == 0)
        {
            i++;
        }
        else if(a[i]%2 != 0 && a[j]%2 != 0)
        {
            j--;
        }
        else{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
}

//Approach 2 : Maintain two array, one for even and another for even
//append this array
//O(n) -> Time and O(n) -> Space


int main()
{
    int a[] = {3, 1, 2, 4};
    sortArrayByParity(a, 4);
    for(int i=0; i<4; i++)
        cout<<a[i]<<" ";
    return 0;
}