#include<iostream>
using namespace std;

int main()
{
    int **p = new int*[10];
    //cout<<sizeof(p)<<endl;
    for(int i=0; i<10; i++)
    {
        p[0] = new int[20];
        for(int j=0; j<20; j++) cin>>p[i][j];
    }
    
    for(int i=0; i<20; i++)
    {
        delete [] p[i];
    }
    
    delete [] p;
    return 0;
}