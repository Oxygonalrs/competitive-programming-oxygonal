#include<iostream>
using namespace std;

void swap(int *a, int a1, int a2)
{
    int temp = a[a1];
    a[a1] = a[a2];
    a[a2] = temp;
}

int partion(int *a, int start, int end)
{
    int count = 0;
    // int pivot = a[start];
    for(int i=start+1; i<=end; i++)
    {
        if(a[start] >= a[i])
            count++;
    }
    swap(a, start, start+count);
    int i = start, j = end;
    while(i<j)
    {
        if(a[i] <= a[start+count]) 
        {
            i++;
        }
        else if(a[j] > a[start+count])
        {
            j--;
        }
        else{
            swap(a,i,j);
            i++;
            j--;
        }
    }
    return count+start;
}

void quickSort(int *a, int start, int end)
{
    if(start >= end) return;
    int c = partion(a, start, end);
    quickSort(a, start, c-1);
    quickSort(a, c+1, end);
}

int main()
{
    int a[] = {5,5,8,9,5,5,6,7};
    int size = 8;
    quickSort(a, 0, size-1);
    for(int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

// #include<iostream>
// using namespace std;

// void swap(int *a, int* b)
// {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// int partition(int a[],  int si, int ei)
// {
// 	int ans = 0;
// 	int pivot = a[si];
// 	for(int i=si+1; i<=ei; i++)
// 	{
// 		if(a[i] <= pivot)
// 		{
// 			ans++;
// 		}
// 	}
// 	int pivotIndex = ans + si;
// 	a[si] = a[pivotIndex];
// 	a[pivotIndex] = pivot;
// 	int i = si;
// 	int j = ei;
// 	while(i<pivotIndex && j >pivotIndex)
// 	{
// 		if(a[i]<= pivot)
// 		{
// 			i++;
// 		}
// 		else if(a[j]>pivot)
// 		{
// 			j--;
// 		}
// 		else{
// 			swap(a[i], a[j]);
// 			i++;
// 			j--;
// 		}
// 	}
// 	return pivotIndex;
// }

// void quickSort(int a[], int si, int ei)
// {
// 	if(si >= ei)
// 	{
// 		return;
// 	}
// 	int p = partition(a, si, ei);
// 	quickSort(a, si, p- 1);
// 	quickSort(a, p +1, ei);
// }

// int main()
// {
// 	int a[] = {5, 8, 7, 2, 3, 1, 9};
// 	quickSort(a, 0, 6);
// 	for(auto i:a)
// 	{
// 		cout<<i<<" ";
// 	}
// }