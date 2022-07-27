#include<iostream>
using namespace std;

int arraySum(int *a, int size)
{
    if(size == 0) return 0;
    int sum = a[0];
    int otherSum = arraySum(a+1, size - 1);
    return sum + otherSum;
}
bool isPresent(int *a, int size, int x)
{
    if(size == 0) return false;
    if(a[0] == x) return true;
    bool ispresent = isPresent(a+1, size-1, x);
    return ispresent;
}

int main()
{
    int a[] = {5, 10, 9, 11, -3};
    int size = 5;
    cout<<"Sum: "<<arraySum(a, size)<<endl;
    cout<<"IsPresent: "<<isPresent(a, size, 4)<<endl;
    return 0;
}