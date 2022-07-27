#include<iostream>
using namespace std;

void generate_permutaion(char* in, int i)
{
    // Base case
    if(in[i] == '\0')
    {
        cout<<in<<endl;
        return;
    }

    // Recursion case
    for(int j=i; in[j]!='\0'; j++)
    {
        swap(in[i], in[j]);
        generate_permutaion(in, i+1);
        
        // BackTracking
        swap(in[i], in[j]);
    }
}

int main()
{
    char in[100];
    cin>>in;
    generate_permutaion(in, 0);
}