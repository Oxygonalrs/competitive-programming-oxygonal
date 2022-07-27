#include<iostream>
using namespace std;

// Number to Spellings
// 2048 --> Two zero four eight

char words[][10] = {"zero", "first","second", "three", "four","five","six","seven","eight","nine"};
void printSpelling(int n)
{
    if(n==0) return;
    printSpelling(n/10);
    cout<<words[n%10]<<" ";
}

int main()
{
    int n = 2048;
    printSpelling(n);
}