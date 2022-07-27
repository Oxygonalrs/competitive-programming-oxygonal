#include<iostream>
#include<list>
using namespace std;

class Book{
    public:
    string name;
    int price;
    Book()
    {

    }
    Book(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};

template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while(start != end)
    {
        if(cmp(*start, key))
        {
            return start;
        }
        start++;
    }
    return end;
}

class BookCompare{
    public:
    bool operator()(Book A, Book B)
    {
        if(A.name == B.name)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Book b1("C++", 100);
    Book b2("Python", 120);
    Book b3("Java", 130);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book key("C#", 110);
    // Book key("C++", 110);

    BookCompare cmp;
    /*
    if(cmp(b1, key))
    {
        cout<<"True same books";
    }*/

    auto it = search(l.begin(), l.end(), key, cmp)
    ;if(it != l.end())
    {
        cout<<"Book found";
    }
    else{
        cout<<"No book found";
    }
}