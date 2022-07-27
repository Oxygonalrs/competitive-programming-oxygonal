#include <iostream>
//#include "0. class.cpp"
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int main()
{
    // Node n1(1);
    // Node * head = &n1;
    // Node n2(2);
    // n1.next = &n2;
    //cout<<head->data<<" "<<n1.data<<" "<<n2.data<<endl;
    

    //Dynamically
    // Node* n1 = new Node(1);
    // Node *head = n1;
    // Node* n2 = new Node(2);
    // Node* n3 = new Node(3);
    // Node* n4 = new Node(4);
    // Node* n5 = new Node(5);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    return 0;
}