/*
Problems involving Linear Recurrences
f(i) = f(i - 1) + f(i - 2)
nth tern of the recurrence

LR is a function which each term of the seq is a linear combination of previous terms 

Matrix Exponential  k^3logN for fibonacci k = 2
Step 1 - Find the value K.
Step 2 - Find out first k terms of the sequence.
Step 3 - Find Transformation matrix

Let's take an example
f(i) = 1.f(i-1) + 2.f(i-2) + 0.f(i-3) + 4f(i-4) = Summation from j=1 to K (Cj*f(i-j));

0 1 0 0     f(i-4)   =   f(i-3)
0 0 1 0     f(i-3)   =   f(i-2)
0 0 0 1     f(i-2)   =   f(i-1)
4 0 2 1     f(i-1)   =   f(i)

How to find generlize matrix 

1) By using Identity Matrix
2) If you constant f(i) = 1.f(i-1) + 2.f(i-2) + 0.f(i-3) + 4f(i-4) + d

0   1   0   0
0   0   1   0
0   0   0   1
ck  ..  c2  c1

0   1   0   0   0
0   0   1   0   0
0   0   0   1   0
ck  ..  c2  c1  1
0   0   0   0   1

*/

#include<iostream>
using namespace std;

int main()
{

}