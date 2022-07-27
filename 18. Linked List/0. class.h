class Node{
    public:
    int data;
    Node* next;
    Node(int element)
    {
        data = element;
        next = NULL;
    }
};

void print(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}