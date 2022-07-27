#include<iostream>
using namespace std;

// Please take care for a number which has zero

void generate_string(char* in, char* out, int i, int j)
{
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    //rec case
    //One digt at time
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    // Here is a Bug
    if(digit != 0)
        generate_string(in, out, i+1, j+1);

    if(in[i+1] != '\0')
    {
        int secondDigit = in[i+1] - '0';
        int no = digit*10 + secondDigit;
        if(no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;
            generate_string(in, out, i+2, j+1);
        }
    }
    return;
}

int main()
{
     char in[100];
     char out[100];
     cin>>in;
     generate_string(in, out, 0, 0);
}