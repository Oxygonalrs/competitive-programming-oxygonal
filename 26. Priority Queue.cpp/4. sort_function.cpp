#include<iostream>
#include<vector>
// #include<queue>
using namespace std;

template <typename T>
class priority_queue{
	vector<T> arr;
	public:
	priority_queue(){}

	void push(T element)
	{
		arr.push_back(element);
		int childIndex = arr.size() - 1;
		while(childIndex > 0)
		{
			int parentIndex = (childIndex - 1)/2;
			if(arr[childIndex] < arr[parentIndex])
			{
				T temp = arr[childIndex];
				arr[childIndex] = arr[parentIndex];
				arr[parentIndex] = temp;
			}
			else
			{
				break;
			}
			childIndex = parentIndex;
		}
	}

	void pop()
	{
		if(empty())
		{
			return;
		}
		int lastIndex = arr.size() - 1;
		arr[0] = arr[lastIndex];
		arr.pop_back();
		int minIndex = 0;
		while(2*minIndex + 1 < arr.size())
		{
			int temp = minIndex;
			if(arr[minIndex] > arr[2*minIndex + 1])
			{
				temp = 2*minIndex + 1;
			}
			if(2*minIndex + 2 < arr.size() && arr[temp] > arr[2*minIndex + 1])
			{
				temp = 2*minIndex + 1;
			}
			if(temp == minIndex)
			{
				break;
			}
		 	T temp2 = arr[temp];
			arr[temp] = arr[minIndex];
			arr[minIndex] = temp2;
			minIndex = temp;
		}
	}

	bool empty()
	{
		return arr.size() == 0;
	}

	int size()
	{
		return arr.size();
	}

	T top()
	{
		if(empty())
		{
			return 0;
		}
		return arr[0];
	}
};

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int*arr, int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void sort(int *arr, int size)
{
	if(size == 0 || size == 1)
	{
		return;
	}
	// int leftChild = 2*parentIndex + 1;
	// int rightChild = 2*parentIndex + 2;
	for(int i=1; i<size; i++)
	{
		int childIndex = i;
		while(childIndex > 0)
		{
			int parentIndex = (childIndex - 1)/2;	
			if(arr[parentIndex] < arr[childIndex])
			{
				// int temp = arr[parentIndex];
				// arr[parentIndex] = arr[childIndex];
				// arr[childIndex] = temp;
				swap(&arr[parentIndex], &arr[childIndex]);
			}
			else{
				break;
			}
			childIndex = parentIndex;
		}
	}
	while(size > 1)
	{
		// int temp = arr[0];
		// arr[0] = arr[size - 1];
		// arr[size - 1] = temp;
		swap(&arr[0], &arr[size -1]);
		size--;
		int parentIndex = 0;
		int leftChildIndex = 2*parentIndex + 1;
		int rightChildIndex = 2*parentIndex + 2;

		while(leftChildIndex < size)
		{
			int minIndex = parentIndex;
			if(arr[minIndex] < arr[leftChildIndex])
			{
				minIndex = leftChildIndex;
			}
			if(rightChildIndex < size && arr[minIndex] < arr[rightChildIndex])
			{
				minIndex = rightChildIndex;
			}
			if(minIndex == parentIndex)
			{
				break;
			}
			// int temp = arr[parentIndex];
			// arr[parentIndex] = arr[minIndex];
			// arr[minIndex] = temp;
			swap(&arr[minIndex], &arr[parentIndex]);
			parentIndex = minIndex;
			leftChildIndex = 2*parentIndex + 1;			
			rightChildIndex = 2*parentIndex + 2;			
		}
	}
}
 
int main()
{

	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	// int arr[] = {10, 8 ,6 ,7,2 ,9, 5,7};
	int arr[] = {10, 8 ,6 ,7,2 ,9, 5,7};
	cout<<"Befor Sort : ";
	print(a,n);
	sort(a, n);
	cout<<"After Sort : ";
	print(a, n);

	// priority_queue<int> q;
	// q.push(5);
	// q.push(6);
	// q.push(8);
	// q.push(7);
	// q.push(10);
	// cout<<q.size()<<endl;
	// cout<<q.empty()<<endl;
	// cout<<q.top()<<endl;
	// q.pop();
	// cout<<q.top()<<endl;
	// q.pop();
	// cout<<q.top()<<endl;
	// q.pop();
	// cout<<q.top()<<endl;
	// q.pop();
	// cout<<q.top()<<endl;
	// q.pop();

	return 0;
}