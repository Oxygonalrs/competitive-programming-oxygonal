#include<iostream>
using namespace std;

int main()
{   
    //Memory Allocation
    //8 byte at stack and 4 byte at Heap Memory
    int *p = new int;
    cout<<p<<endl;
    cout<<*p<<endl;
    *p = 10;
    cout<<*p<<endl;

    int *a = new int[50];
    cout<<sizeof(4)<<endl;

    //delete address and pointer is not dealloted and pointer pointer there that will delete
    delete p;
    delete [] a;
    return 0;
}