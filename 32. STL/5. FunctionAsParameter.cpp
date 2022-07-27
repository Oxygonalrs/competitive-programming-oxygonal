#include<iostream>
using namespace std;

bool compare(int a, int b)
{
    cout<<"Comparing "<<a<<" and "<<b<<endl;
    return a > b;
}

void bubbleSort(int a[], int n, bool (&cmp)(int a, int b))
{
    for(int itr = 1; itr <= n-1; itr++)
    {
        for(int j=0; j<=(n-itr-1); j++)
        {
            if(cmp(a[j], a[j+1]))
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{

    bubbleSort(a, n, compare)
    cout<<"Chutiya "; 
}