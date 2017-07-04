#include <iostream>
using namespace std;
void print(int , int);
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b= temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	for(int i=0; i<n-1; i++)
	{
		min_idx = i;
		for(int j=i+1; j<n; j++)
			if(arr[j] < arr[min_idx])
				min_idx = j;
		
		swap(&arr[i], &arr[min_idx]);
	}
}

void insertionSort(int arr[], int n)
{
	int i, j, key;
	for(int i=0; i<n; i++)
	{
		key = arr[i];
		j=i-1;
		while(arr[j] > key && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]  = key;
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap (&arr[i], &arr[j]);
		}
	}
	swap (&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{	 
		int p = partition(arr, low, high); 
		quickSort(arr, low, p - 1); 
		quickSort(arr, p + 1, high);
	}
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;
	if(largest != i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}	
}

void heapsort(int arr[], int n)
{
	for(int i = n/2 - 1; i>=0; i--)
		heapify(arr, n, i);
	for(int i=n-1; i>=0; i--){
		swap(&arr[i], &arr[0]);
		heapify(arr, i, 0);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	
	int L[n1], R[n2];
	
	for(int i=0; i<n1; i++)
		L[i] = arr[l+i];
	for(int j=0; j<n2; j++)
		R[j] = arr[m+1+j];
		
	i=0;
	j=0;
	k=l;
	
	while(i < n1 && j < n2){
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l , int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		
		merge(arr, l, m ,r);
	}
}

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"   ";
}

int main(void)
{
	int arr[]= {10, 7, 8, 9, 1, 5};
	int n= sizeof(arr)/sizeof(arr[0]);
//	quickSort(arr, 0, n-1);
//	heapsort(arr, n);
	mergeSort(arr, 0, n-1);
	cout<<"Sorted array: ";
//	selectionSort(arr, n);
//	insertionSort(arr, n);
//	bubbleSort(arr, n);
	print(arr, n);
}
