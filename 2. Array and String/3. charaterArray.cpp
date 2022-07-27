#include<iostream>
using namespace std;
int main()
{
    int a[5];
    char b[500];
    // cin>>b;
    cin.getline(b,500,'#');
    cout<<a<<endl;
    cout<<b;

    //cout<<"Integer: "<<a<< "\nCharacter: "<<b;

    return 0;
}