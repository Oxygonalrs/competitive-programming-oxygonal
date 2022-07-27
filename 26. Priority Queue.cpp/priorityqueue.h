//Heap is complete Binary Tree
//Heap Sort O(nlong) -> Time and O(n) -> space
#include<vector>

class priorityQueue{
    vector<int> pq;
    public:
    priorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty()) return 0;
        return pq.at(0);
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;

            childIndex = parentIndex;
        }
    }

    int remove(){
        if(isEmpty()) return -1;

        int finalIndex = pq.size() - 1;
        int ans = pq[0];
        pq[0] = pq[finalIndex];
        pq[finalIndex] = ans;
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = parentIndex*2 + 1;
        int rightChildIndex = parentIndex*2 + 2;
        while(leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }

            if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex) break;

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = parentIndex*2 + 1;
            rightChildIndex = parentIndex*2 + 2;
        }

        return ans;
    }

};