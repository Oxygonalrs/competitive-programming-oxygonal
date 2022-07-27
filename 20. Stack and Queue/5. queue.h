//Queue By Linked List
template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class queue{
    private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
    queue(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    int getsize()
    {
        return size;
    }
    bool empty()
    {
        return head == NULL;
    }
    void push(T element)
    {
        Node<T>* newNode = new Node<T>(element);
        if(empty())
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }   
        size++;
    }
    T pop()
    {
        if(head == NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        Node<T>* temp = head;
        T ans = head->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T front()
    {
        if(head == NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return head->data;
    }
};




//Queue By Using array
// template<typename T>
// class queue{
//     private:
//     T *data;
//     int firstIndex;
//     int nextIndex;   
//     int size;
//     int capacity;
//     public:
//     queue(){
//         data = new T[5];
//         firstIndex = -1;
//         nextIndex = 0;
//         size = 0;
//         capacity = 5;
//     }
//     int getsize()
//     {
//         return size;
//     }
//     bool empty()
//     {
//         return size == 0;
//     }
//     void push(T element)
//     {
//         if(size == capacity)
//         {
//             T* newData = new T[2*capacity];
//             //This is not working
//             //May be we cant called function in class
//             // for(int i=0; i<size; i++)
//             // {
//             //     newData[i] = front();
//             //     pop();
//             // }
//             int j=0;
//             for(int i = firstIndex; i<capacity; i++)
//             {
//                 newData[j] = data[i];
//                 j++;
//             }
//             for(int i = 0; i<firstIndex; i++)
//             {
//                 newData[j] = data[i];
//                 j++;
//             }
//             delete [] data;
//             data = newData;
//             firstIndex = 0;
//             nextIndex = capacity;
//             capacity*=2;
//         }
//         data[nextIndex] = element;
//         nextIndex = (nextIndex + 1) % capacity;
//         if(firstIndex == -1)
//         {
//             firstIndex = 0;
//         }
//         size++;
//     }
//     T front()
//     {
//         if(empty())
//         {
//             cout<<"Queue is Empty !"<<endl;
//             return 0;
//         }
//         return data[firstIndex];
//     }
//     T pop()
//     {
//         if(empty())
//         {
//             cout<<"Queue is Empty !"<<endl;
//             return 0;
//         }
//         T ans = data[firstIndex];
//         firstIndex = (firstIndex + 1)% capacity;
//         size--;
//         if(size==0)
//         {
//             firstIndex = -1;
//             nextIndex = 0;
//         }
//         return ans;
//     }
//     void print()
//     {
//         for(int i=0; i<size; i++)
//         {
//             cout<<i<<"  "<<data[i]<<endl;
//         }
//     }
// };