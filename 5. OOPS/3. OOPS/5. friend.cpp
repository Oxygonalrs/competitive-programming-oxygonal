#include<iostream>
using namespace std;

void Test();

class Bus {
    public:
    void print();
};

class Truck{
    private: 
    int x = 5;
    public:
    int y;
    protected:
    int z;

    //friend void Bus :: print();
    friend class Bus;
    friend void Test();
};

void Bus :: print()
{   Truck t;
    t.x = 10;
    t.y = 10;
    cout<<t.x<<" "<<t.y<<endl;
}

void Test()
{
    Truck t;
    t.x = 10;
    t.y = 10;
    cout<<t.x<<" "<<t.y<<endl;
}

int main()
{
    Bus b;
    b.print();
    Test();
    return 0;
}