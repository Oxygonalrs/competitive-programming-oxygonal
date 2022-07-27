#include<iostream>
#include<queue>
using namespace std;

class Person{
    public:
    string name;
    int age;
    
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class PersonCampare{
    public:
    bool operator()(Person A, Person B)
    {
        return A.age < B.age;
    }
};

int main()
{
    priority_queue<Person, vector<Person>, PersonCampare> pq;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string name;
        int age;
        cin>>name>>age;
        Person p(name, age);
        pq.push(p);
    }
    //klogN - For top K Elements
    while(!pq.empty())
    {
        cout<<pq.top().name<< " "<<pq.top().age<<endl;
        pq.pop();
    }

    return 0;
}