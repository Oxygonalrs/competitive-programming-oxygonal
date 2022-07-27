#include <iostream>
using namespace std;
#include "1. Trie.h"

int main()
{
    Trie t;
    t.insertWord("h");
    cout<<t.count<<endl;
    cout<<t.searchWord("Hi")<<endl;
    // t.removeWord("Hi");
    cout<<t.searchWord("h")<<endl;
    //Case Sensitive
    cout<<t.searchWord("H")<<endl;
    //Suffix Tries
}