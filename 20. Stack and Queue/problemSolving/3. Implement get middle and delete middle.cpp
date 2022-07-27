//Implement a stack with push, pop, getMiddle, deleteMiddle Operations in O(1) time and O(1) space
//floor value means minimum value 5.7 == 5
#include <iostream>
using namespace std;
//implementation By using Doubly Linked List
class Node{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        previous = NULL;
    }
};
class Stack{
    private:
    int size;
    Node* middle;     //To track the middle Element
    Node* top;
    public:
    Stack()
    {
        size = 0;
        middle = NULL;
        top = NULL;
    }
    void push(int data)
    {

        Node * newNode = new Node(data);
        if(top == NULL)
        {
            top = newNode;
            middle = newNode;
            return;
        }
        // if(size & 1)  It is check by using bitwise operation
        if(size % 2 == 0)
        {
            newNode->next = top;
            top->previous = newNode;
            top = newNode;
        }
        else{
            middle = middle->previous;
            newNode->next = top;
            top->previous = newNode;
            top = newNode;
        }
        size++;
    }
    void pop()
    {
        if(size%2==0)
        {
            Node* temp = top;
            middle = middle->next;
            top = top->next;
            delete temp;
        }
        else
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        size--;
    }
    void deleteMiddleElement()
    {
        if(size%2==0)
        {
            Node* temp = middle;
            middle->previous->next = middle->next;
            middle->next->previous = middle->previous;
            delete temp;
        }
    }
    int getMiddleElement()
    {
        if(middle!=NULL)
        {
            return middle->data;
        }
        return -1;
    }
};



int main()
{
    Stack s;
    s.push(1);
    s.push(5);
    s.push(5);
    s.push(10);
    s.push(2);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.getMiddleElement()<<endl;
}