#include<iostream>
using namespace std;

// Task 
// -> Move all Disks from A to C.
// -> Pick 1 Disk at Time
// -> Can't place a big on small disk

void move(int n, char src, char helper, char dest)
{
    if(n==0) return;

    move(n-1, src, dest, helper);
    cout<<"Shift disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    move(n-1, helper, src, dest);
}
int main()
{
    int n;
    cin>>n;
    move(n, 'A', 'B', 'C');
}