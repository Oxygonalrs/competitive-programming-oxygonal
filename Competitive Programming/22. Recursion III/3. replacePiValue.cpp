#include<iostream>
using namespace std;

// Replace "Pi" with "3.14"
// xpighpilmpipi = x3.14gh3.14lm3.143.14

void replacePi(char a[], int i)
{
    if(a[i] == '\0' || a[i+1] == '\0') return;

    if(a[i] == 'p' && a[i+1] == 'i')
    {
        int j = i+2;
        //take j to end of the array
        while(a[j] != '\0')
        {
            j++;
        }
        while(j>=i+2)
        {
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacePi(a, i+4);
    }
    else{
        replacePi(a, i+1);
    }
    return ;
}

int main()
{
    char a[1000] = "xpighpilmpipi";
    replacePi(a, 0);
    cout<<a<<endl;
}