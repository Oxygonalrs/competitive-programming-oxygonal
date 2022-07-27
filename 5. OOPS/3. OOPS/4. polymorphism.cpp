#include<iostream>
using namespace std;

//Function overloading and operator overloading

int test(int a, int b)
{
    return -1;
}

int test(int a)
{
    return -1;
}

int test()          //We can not make void test() 
{
    return -1;
}

//Method/Function overriding
class Vehicle{
    public:
    string color;
    // virtual void print(){
    //     cout<<"Vehicle Print"<<endl;
    // } 

    //pure virtual function
    virtual void print () = 0;
};

class Car: public Vehicle{
    public:
    int tyre;
    void print(){
        cout<<"Car Print"<<endl;
    }
};

int main()
{
    //Vehicle v;
    Car c;
    // v.print();
    // c.print();

    //Vehicle *v1 = new Vehicle;
    Vehicle *v2 ;
    //v2 = &v;
    v2 = &c;
    //v1->print();
    v2->print();
    return 0;
}