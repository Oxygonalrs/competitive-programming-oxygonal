/*

Birthday Paradox Problem [WarmUp]
What is the minimum number of people that should be present
in a hall so that there's 50% chance of two people having 
the same birthday?

*/

#include<iostream>
using namespace std;

int main()
{
    float x = 1.0;
    int people = 0;
    float num = 365;
    float deno = 365;
    float p;
    cin>> p;
    if(p == 1.0)
    {
        cout<<"366"<<endl;
        return 0;
    }
    while(x > 1 - p)
    {
        x = x*(num)/deno;
        num--;
        people++;
        cout<<"people : "<<people<< " and x : "<<x<<endl;
    }
    //Same answer when compare with GFG

}