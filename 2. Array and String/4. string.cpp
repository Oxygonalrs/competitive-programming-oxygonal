#include<iostream>
#include<cstring>   //character string 
#include<string.h>
using namespace std;
int main()
{
    
    char s1[500] = "Mayur Rajesh Bansod";
    char s2[500] = "Mayur Rajesh Bansod";
    char s3[500] = "abc";
    //Not working on
    string s = "Mayur";
    // string s2 = "Mayur";
    cout<<"Length: "<<strlen(s1)<<endl;
    cout<<"Length: "<<s.length()<<endl;
    cout<<"Compair: "<<strcmp(s1, s2)<<endl;
    cout<<"Copy: "<<strcpy(s3, s1)<<endl;
    int a[5][5] = {0};
    cout<<a<<endl;
    cout<<*(a + 2*5+2);
    return 0;
}
//In 2D array while passing to function
//we need pass column value
//a[][5] - like this

//Check Permutation
//make a char array of size of 256 and traverse 
//on one string and ++ and traverse on other and --