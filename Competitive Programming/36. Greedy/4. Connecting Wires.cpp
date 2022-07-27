#include <bits/stdc++.h>
using namespace std;

/*
There are n white dots and n black dots, equally spaced in a line
You want to connect each white dot with some one black dot,with a 
minimum total length of wire.

Find the total length of wire needed;

Input - 
White Dots Position = [1, 3, 4]
Black Dots Position = [2, 5, 6]
*/

int main()
{
    int white[] = {1, 3, 4};
    int blackarry[] = {2, 5, 6};
    int n = 3;
    sort(white, white + n);
    sort(blackarry, blackarry + n);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += abs(white[i] - blackarry[i]);
    }
    cout<<ans<<endl;
    return 0;
}