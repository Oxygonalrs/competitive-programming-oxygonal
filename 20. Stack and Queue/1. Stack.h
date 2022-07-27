//Stack Using Linked List
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
class stack{
    private:
    Node<T>* head;
    int size;
    public:
    stack()
    {
        head = NULL;
        size = 0;
    } 
    T getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void push(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }
    T pop()
    {
        // if(size() == 0)
        if(head == NULL)
        {
            cout<<"Stack is Empty"<<" pop "<<endl;
            return 0;
        }
        Node<T>* temp = head;
        T ans = head->data;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }
    T top()
    {
        if(head == NULL)
        {
            cout<<"Stack is Empty"<<" top "<<endl;
            return 0;
        }
        return head->data;
    }
};


//Stack Using Array

// template <typename T>
// class stack{
//     private:
//     int nextIndex;
//     int *data;
//     // T *data;
//     int capacity;
    
//     public:  
//     stack(int totalSize)
//     {
//         data = new int[totalSize];
//         // data = new T[totalSize];
//         nextIndex = 0;
//         this->capacity = totalSize;
//     }
    
//     int size(){
//         return nextIndex;
//     }

//     bool isEmpty(){
//         // if(nextIndex == 0) return true;
//         // return false;

//         return nextIndex == 0;
//     }

//     // void push(T element)
//     void push(int element)
//     {
//         if(nextIndex == capacity) 
//         {
//             cout<<"Stack Full "<<endl;
//             return;
//         }
//         data[nextIndex++] = element;
//     }

//     int pop()
//     {
//         if(isEmpty())
//         {
//             cout<<"Stack is Empty"<<endl;
//             return INT_MIN;
//         }
//         nextIndex--;
//         return data[nextIndex];
//     }

//     int top()
//     {
//         if(size() == 0)
//         {
//             cout<<"Stack is Empty"<<endl;
//             return INT_MIN;
//         }
//         return data[nextIndex - 1];
//     }
// };

//Without Size constraint
// class stack{
//     private:
//     int nextIndex;
//     int *data;
//     int capacity;
    
//     public:  
//     stack()
//     {
//         data = new int[4];
//         // data = new T[totalSize];
//         nextIndex = 0;
//         capacity = 4;
//     }
    
//     int size(){
//         return nextIndex;
//     }

//     bool isEmpty(){
//         // if(nextIndex == 0) return true;
//         // return false;

//         return nextIndex == 0;
//     }

//     int capaCity(){
//         return capacity;
//     }

//     void push(int element)
//     {
//         if(nextIndex == capacity) 
//         {
//             int* newData = new int[capacity*2];
//             for(int i=0; i<capacity; i++)
//             {
//                 newData[i] = data[i];
//             }
//             capacity *= 2;
//             delete [] data;
//             data = newData;
//         }
//         data[nextIndex++] = element;
//     }

//     int pop()
//     {
//         if(isEmpty())
//         {
//             cout<<"Stack is Empty"<<endl;
//             return INT_MIN;
//         }
//         nextIndex--;
//         return data[nextIndex];
//     }

//     int top()
//     {
//         if(size() == 0)
//         {
//             cout<<"Stack is Empty"<<endl;
//             return INT_MIN;
//         }
//         return data[nextIndex - 1];
//     }
// };

// template <typename T>
// class stack{
//     private:
//     int nextIndex;
//     T *data;
//     int capacity;
    
//     public:  
//     stack()
//     {
//         data = new T[4];
//         // data = new T[totalSize];
//         nextIndex = 0;
//         capacity = 4;
//     }
    
//     int size(){
//         return nextIndex;
//     }

//     bool isEmpty(){
//         // if(nextIndex == 0) return true;
//         // return false;

//         return nextIndex == 0;
//     }

//     int capaCity(){
//         return capacity;
//     }

//     void push(T element)
//     {
//         if(nextIndex == capacity) 
//         {
//             T* newData = new T[capacity*2];
//             for(int i=0; i<capacity; i++)
//             {
//                 newData[i] = data[i];
//             }
//             capacity *= 2;
//             delete [] data;
//             data = newData;
//         }
//         data[nextIndex++] = element;
//     }

//     T pop()
//     {
//         if(isEmpty())
//         {
//             cout<<"Stack is Empty"<<endl;
//             return 0;
//         }
//         nextIndex--;
//         return data[nextIndex];
//     }

//     T top()
//     {
//         if(size() == 0)
//         {
//             cout<<"Stack is Empty"<<endl;
//             return 0;
//         }
//         return data[nextIndex - 1];
//     }
// };

template <typename T, typename Y>
class Pair{
    T x;
    Y y;
    
    public:
    void setX(T x)
    {
        this->x =x;
    }

    T getX()
    {
        return x;
    }

    void setY(Y y)
    {
        this->y =y;
    }

    Y getY()
    {
        return y;
    }
};