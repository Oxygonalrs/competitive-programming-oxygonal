#include <iostream>
using namespace std;

//I can make 2D array as well

char keypad[][10] = {"", "", "ABC", "DEF","GHI", "JKL","MNO","PQRS","TUV","WXYZ"};
string getString(int n)
{
    switch (n - 1){
        case 1 :
            return "ABC";
            break;
        case 2 :
            return "DEF";
            break;
        case 3 :
            return "GHI";
            break;
        case 4 :
            return "JKL";
            break;
        case 5 :
            return "MNO";
            break;
        case 6 :
            return "PQRS";
            break;
        case 7 :
            return "TUV";
            break;
        case 8 :
            return "WXYZ";
            break;
        default :
            return "";
    }
}

void generte_name(char* in, char *out, int i, int j)
{
    if(in[i] =='\0')
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int digit = in[i] - '0';
    if(digit == 0 || digit == 1)
    {
        generte_name(in, out, i+1, j);
    }
    for(int k=0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        generte_name(in, out, i+1, j+1);
    }


    return;
}

int main()
{
    char in[100];
    char out[100];
    cin>>in;
    generte_name(in, out, 0, 0);
    
}