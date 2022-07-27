#include<iostream>
using namespace std;

template<typename T>
class StackArray
{
  T *arr;
  int capacity;
  int nextIndex;
  public:
  StackArray()
  {
    arr = new T[5];
    capacity = 5; 
    nextIndex = 0;
  }

  void push(T data)
  {
    if(nextIndex == capacity)
    {

    }
    arr[nextIndex] = data;
    nextIndex ++;
  }
}

int main()
{
   
}