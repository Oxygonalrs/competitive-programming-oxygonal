#include<iostream>
using namespace std;

int stringLength(char *s)
{
    if(s[0] == '\0')
        return 0;
    int smallStringLength = stringLength(s+1);
    return smallStringLength + 1;
}

void removeX(char s[])
{
    if(s[0] == '\0') return;
    if(s[0] != 'x')
    {
        removeX(s+1);
    }
    else{
        int i=1;
        for(; s[i] != '\0'; i++)
        {
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeX(s);
    }
}

void replaceByChar(char s[], char a, char b)
{
    if(s[0] == '\0') return;
    if(s[0] == a)
        s[0] = b;
    replaceByChar(s+1, a, b);
}

void replaceDuplicate(char s[])
{
    if(stringLength(s) == 0) return;
    if(stringLength(s) == 1) return;
    replaceDuplicate(s+1);
    if(s[0] != s[1])
        return;
    else{
        int i=1;
        for(;s[i]!='\0'; i++)
        {
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
    }
}

int main()
{
    char s[] = "aajjnaafnfbboexkfxnnxoxex";
    cout<<"Length: "<<stringLength(s)<<endl;
    removeX(s);
    cout<<"Remove X: "<<s<<endl;
    cout<<"Length: "<<stringLength(s)<<endl;
    replaceByChar(s,'a','b');
    cout<<"Replace A with B: "<<s<<endl;
    replaceDuplicate(s);
    cout<<"Remove Duplicates: "<<s<<endl;
}