#include <iostream>
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

Node* insertAtIndex(Node* head, int i, int data)
{
    Node * newNode = new Node(data);
    Node * curr = head;
    int count = 0;
    if(i==0)
    {
        newNode->next = curr;
        head = newNode;
        return head;
    }
    while(count < i - 1  && curr->next != NULL)
    {
        curr = curr->next;
        count++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* deleteAtIndex(Node* head, int i)
{
    Node * curr = head;
    int count = 0;
    if(i==0)
    {
        head = head->next ;
        delete curr;
        return head;
    }
    while(count < i - 1)
    {
        curr = curr->next;
        count++;
    }
    if(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        // curr->next = temp->next;
        delete temp;
    }
    return head;
}

Node* InsertRecursive(Node* head, int i, int data)
{
    if(head == NULL) return NULL;
    if(i==0)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = InsertRecursive(head->next, i-1, data);
    head->next = temp;
    return head;
}

Node* deleteRecursive(Node* head, int i)
{
    if(head == NULL) return NULL;
    if(i==0)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    Node* temp = deleteRecursive(head->next, i-1);
    head->next = temp;
    return head;
}

int main()
{
    Node * head = takeInput();
    print(head);
    head = insertAtIndex(head,0,10); 
    print(head);
    // head = deleteAtIndex(head,8); 
    // print(head);
    head = InsertRecursive(head,0,11); 
    print(head);
    head = deleteRecursive(head,7); 
    print(head);

    
    return 0;
}