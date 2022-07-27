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

Node* reverse(Node *head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;
    Node *temp = head;
    while(temp != NULL) 
    {
        
        temp = temp->next;
    }
}

bool palimdrome(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        count++; 
        temp = temp->next;
    }
    int mid = count/2;
    cout<<mid<<endl;
    cout<<count<<endl;
    temp = head;
    while(mid != 0){
        temp = temp->next;
        mid--;
    }
    temp = reverse(temp);
    
    while(head != NULL && temp != NULL)
    {
        if(head->data != temp->data) return false;
        head = head->next;
        temp = temp->next;
    }
    return true;
}

int main()
{
    Node * head = takeInput();
    print(head);
    cout<<palimdrome(head);
    
    return 0;
}

