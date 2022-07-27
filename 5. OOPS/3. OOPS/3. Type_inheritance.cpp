#include<bits/stdc++.h>
using namespace std;

//Multiple Inheritance

class Teacher{
    public:
    void print()
    {
        cout<<"Teacher print functions"<<endl;
    }
};
class Student{
    public:
    void print()
    {
        cout<<"Student print functions"<<endl;
    }
};
class TA: public Teacher, public Student{
    public:
    void print()
        {
            cout<<"TA print functions"<<endl;
        }
};

//Hybrid Problem
class Vehicle{
    public:
    // Vehicle(){
    //     cout<<"Vechicle Constructor called !"<<endl;
    // }
    Vehicle(int z){
        cout<<"Vechicle Constructor called !"<<" "<<z<<endl;
    }
    ~Vehicle(){
        cout<<"Vechicle Constructor called !"<<endl;
    }
};

class Car: virtual public Vehicle{
    public:
    Car(): Vehicle(5){
        cout<<"Car Constructor called !"<<endl;
    }
    ~Car(){
        cout<<"Car Constructor called !"<<endl;
    }
};

class Truck : virtual public Vehicle{
    public:
    Truck(): Vehicle(4){
        cout<<"Truck Constructor called !"<<endl;
    }
    ~Truck(){
        cout<<"Truck Constructor called !"<<endl;
    }
};

class Bus : public Car, public Truck{
    public:
    Bus(): Vehicle(3){
        cout<<"Bus Constructor called !"<<endl;
    }
    ~Bus(){
        cout<<"Bus Constructor called !"<<endl;
    }
};

int main()
{
    // TA t;
    // t.Student :: print();
    // t.print();
   
    Bus s;
    return 0;
}