#include <iostream>
using namespace std;

// *Recheck This

//Unique Number - 2
//Example a = [1,1,2,6,5,2,5,7]
//Unique = 3, 7  //Non-decreasing order
//Linear time, No space
//hack.codingblocks.com
int main()
{
    int n;
    cin>>n;
    int no;
    int xori = 0;
    int arr[100005];
    for(int i=0; i<n; i++)
    {
        cin>>no;
        arr[i] = no;
        xori = xori^no;
    }

    int temp = xori;
    int pos = 0;
    while((temp&1)!=1)
    {
        pos++;
        temp = temp>>1;
    }

    int mask = (1<<pos);
    int a = 0;
    int b = 0;
    for(int i=0; i<n; i++)
    {
        if((arr[i]&mask) > 0)
        {
            a = a^arr[i];
        }
    }
    b= xori^a;

    cout<<min(a,b)<<" "<<max(a,b)<<endl;
    return 0;
}