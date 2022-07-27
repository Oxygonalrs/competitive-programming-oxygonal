#include<bits/stdc++.h>
using namespace std;

class Vehicle{
private:
int maxspeed;
public:
    int numTyre ;
    Vehicle(int a){
        cout<<"Vehicle Constuctor is  called !"<< " "<<a;
        cout<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle destructor is  called !";cout<<endl;
    }
protected:
string color = "Red";
};

class Car : public Vehicle{   //It only copy data member and not take-gain with memory address
    public:
    void showFun(){
        cout<<numTyre<<" "<<color<<endl;
    }
    Car(int n,int j) : Vehicle(n){
        cout<<"Cars Constuctor is  called !";cout<<" "<<j<<endl;
    }
    ~Car(){
        cout<<"Cars destructor is  called !";cout<<endl;
    }
};

class HondaCity : public Car{
public:
    void showFun(){
        cout<<numTyre<<" "<<color<<endl;
    }
    HondaCity(int n,int j,int k) : Car(n,j){
        cout<<"HondaCity Constuctor is  called !";cout<<" "<<k<<endl;
    }
    ~HondaCity(){
        cout<<"HondaCity destructor is  called !";cout<<endl;
    }

};

int main()
{
    // Vehicle v;
    // v.numTyre = 10;
    HondaCity c(1,2,3);
    // c.showFun();
    // cout<<c.numTyre<<endl;
    // // //cout<<v.numTyre<<endl;
    // // c.numTyre = 24;
    // // cout<<c.numTyre<<endl;
    // // cout<<v.numTyre<<endl;
    return 0;
}