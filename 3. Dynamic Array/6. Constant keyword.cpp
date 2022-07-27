#include <iostream>
using namespace std;

void f(const int *p)
{

}

int main()
{
    // // const int i = 10;
    // int const i = 10;
    
    // int j = 12;
    // const int &k = j;
    // // k++;     It will give error because it is read only
    // j++;

    // int const j2 = 12;
    // const int &k2 = j2;
    // return 0;

    // int const i = 10;
    // int const *p = &i;

    // int j=12;
    // int *p3 = &j;
    // f(p3);

    int i = 10;
    int j = 20;
    int const *p = &i; //i will be constant and p is not constant
    //(*p)++;
    p = &j;
    int * const p2 = &i; //i will be change but p will not change
    (*p2)++;
    // p2 = &j;

    int const * const p3 = &i;
}