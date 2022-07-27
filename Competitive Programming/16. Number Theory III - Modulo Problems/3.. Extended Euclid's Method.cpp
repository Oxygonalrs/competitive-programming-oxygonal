// Multiplicative Modulo Inverse
// (a*b)%m = 1

// if modulo inverve exist only when gcd(a, b) is 1.

#include<iostream>
using namespace std;

// Extended Euclid's Algorithms
// Solve eq. of this form
// Ax + By = GCD(A, B);
// Major Application
// 1) Multiplicative Modulo 
// 2) Linear Diophonative eqn's

// Bx1 + (A%B)y1 = GCD(B, A%B)
// [A%B = A - [A/B]*B] = GCD(B, A%B)

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a*b/gcd(a, b);
}

int x, y, GCD;
void extendedEuclidAlgorithm(int a, int b){
    if(b==0){
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    extendedEuclidAlgorithm(b, a%b);
    int cX = y;
    int cY = x - (a/b)*y;

    x = cX;
    y = cY;
}

int inverseModulo(int a, int m)
{
    extendedEuclidAlgorithm(a, m);

    return (x+m)%m;
}

int main()
{
    // extendedEuclidAlgorithm(18, 30);
    cout<<inverseModulo(6,7);cout<<endl;
    cout<<inverseModulo(8,7);cout<<endl;
    cout<<inverseModulo(18,7);cout<<endl;
}   