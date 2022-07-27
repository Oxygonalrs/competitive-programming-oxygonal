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

Node* takeInput()
{
    int data;
    cin>>data;
    Node *head = NULL;
    Node *temp = NULL;
    while(data != -1)
    {
        if(head == NULL)
        {
            Node *n = new Node(data);
            head = n;
            temp = n;
        }
        else
        {
            Node *n = new Node(data);
            temp->next = n;
            temp = temp->next;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node * head = takeInput();
    print(head);

    //Statically
    // Node n1(1);
    // Node *head = &n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);

    // Dynamically
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
    // print(head);
    return 0;
}