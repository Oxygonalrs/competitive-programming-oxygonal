#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class fruit{
    public:
    string name;
    int price;
    fruit(string name, int price){
        this -> name = name;
        this -> price = price;
    }
};

class student{
    public:
    string fname;
    string lname;
    string rollno;
    student(string fname, string lname, string rollno)
    {
        this->fname = fname;
        this->lname = lname;
        this->rollno = rollno;
    }
    bool operator==(const student &s) const
    {
        return rollno == s.rollno;
    }
};

class HashFn{
    public:
    size_t operator()(const student &s)const {
        return s.fname.length() + s.lname.length();
    }
};

int main()
{
    // pair<string, int> p("Mango", 59);
    // map<fruit, int> mpp;
    // // mpp.insert(p);
    // // mpp.insert(make_pair("Banana", 89));
    // mpp.insert(make_pair(fruit("banana", 100), 200));
    // //NO because we are storing fruit and not address
    // // mpp.insert(make_pair(new fruit("banana", 100), 200));
    
    // multimap<char, string> mpp;
    // mpp.insert(make_pair('b', "batman"));
    // mpp.insert(make_pair('a', "apple"));
    // mpp.insert(make_pair('b', "boat"));
    // mpp.insert(make_pair('a', "angry"));
    // mpp.insert(make_pair('c', "cat"));
    // for(auto i : mpp)
    // {
    //     cout<<i.first<<" -> "<<i.second<<endl;
    // }
    // auto it1 = mpp.lower_bound('b');
    // auto it2 = mpp.upper_bound('c');
    // for(auto it= it1; it!=it2; it++)
    // {
    //     cout<<it->first<<" -> "<<it->second<<endl;
    // }

    unordered_map<student, int, HashFn> h;
    student s1("Pratik", "kumar", "101");      
    student s2("Pratik", "Gupta", "102");      
    student s3("Rahul", "kumar", "103");      
    student s4("Pratik", "kumar", "101");      
    h[s1] = 101;
    h[s2] = 102;
    h[s3] = 103;
    h[s4] = 104;
    for(auto i : h)
    {
        cout<<i.first.fname<<" "<<i.first.lname<<" "<<i.first.rollno<<"    "<<i.second<<endl;
    }
    auto i = h.find(s4);
    cout<<i->second<<endl;
    return 0;
}