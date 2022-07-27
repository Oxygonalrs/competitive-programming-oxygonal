#include<iostream>
using namespace std;
#include "0. class.h"

Node * insertRecursive(Node * head, int position, int value)
{
    if(head == NULL){
        Node* temp = new Node(value);
        temp->next = NULL;
        return temp;
    }
    if(position == 0)
    {
        Node* temp = new Node(value);
        temp->next = head;
        return temp;
    }
    head->next = insertRecursive(head->next, position - 1, value);
    return head;
}

Node* deleteRecursive(Node* head, int position)
{
    if(head == NULL) return NULL;
    if(position == 0)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteRecursive(head->next, position - 1);
    return head;
}

Node* reverseLinkedList(Node* head)
{
    if(head == NULL || head->next == NULL) return head;
    Node* temp = reverseLinkedList(head->next);
    Node* temp1 = temp;
    while(temp1 -> next != NULL) {temp1 = temp1->next;}
    temp1 -> next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    Node * head = NULL;
    head = insertRecursive(head, 0, 1);
    head = insertRecursive(head, 5, 3);
    head = insertRecursive(head, 5, 4);
    head = insertRecursive(head, 5, 5);
    head = insertRecursive(head, 5, 6);
    head = insertRecursive(head, 1, 2);
    print(head);
    head = reverseLinkedList(head);
    // head = deleteRecursive(head, 8);
    print(head);
}