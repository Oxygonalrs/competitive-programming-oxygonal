#include<iostream>
using namespace std;


//General formula for consenquence is 2^n
int subs(string input, string * output)
{
    if(input.empty())
    {
        output[0] = "";
        return 1;
    }
    int smallOutput = subs(input.substr(1), output);
    for(int i=0; i<smallOutput; i++)
    {
        output[i+ smallOutput] = input[0] + output[i];
    }
    return 2*smallOutput;
}

int main()
{
    string s;
    cin>>s;
    string* output = new string[1000];
    int sub = subs(s, output);
    cout<<"Subsequence: "<<sub<<endl;
    for(int i=0; i<sub; i++)
        cout<<output[i]<<endl;
}