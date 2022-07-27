#include<iostream>
#include<set>
#include<string>
using namespace std;

void generate_permutaion(char* in, int i, set<string> &s)
{
    // Base case
    if(in[i] == '\0')
    {
        // cout<<in<<endl;
        s.insert(in);
        return;
    }

    // Recursion case
    for(int j=i; in[j]!='\0'; j++)
    {
        swap(in[i], in[j]);
        generate_permutaion(in, i+1, s);
        
        // BackTracking
        swap(in[i], in[j]);
    }
}

int main()
{
    char in[100];
    cin>>in;
    set<string> s;
    generate_permutaion(in, 0, s);
    for(auto i : s)
    {
        cout<<i<<endl;
    }
}