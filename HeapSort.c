#include <stdio.h>
#include <ctype.h>
#define size 10
//int A[11] = {0 ,4 ,2 ,3 ,5 ,1 ,8 ,7 ,9 ,6 ,10};
int heap_size = 10;
void maxHeapify(int A[], int i)
{
	int	largest = i, temp;
	int l = 2 * i;
	int r = 2 * i + 1;
	if (l <= heap_size && A[l] > A[i])
		largest = l;
	if( r <= heap_size && A[r] > A[i] && A[r] > A[l])
		largest = r;
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, largest);
	}
}

void buildMaxHeap(int A[])
{
	int i = 0;
	for (i = 10/2; i > 0;i--)
		maxHeapify(A, i);
}

void HeapSort(int A[])
{
	buildMaxHeap(A);
	int i = 0,temp,j;
	printf("\n");
	for(i = 0;i <= 10; i++)
		printf("%d\t",A[i]);
	for(i = 10; i >= 2; i--)
	{
		temp = A[1];
		A[1] = A[heap_size];
		A[heap_size] = temp;
		heap_size--;
		maxHeapify(A, 1);

	}
}

int main()
{
	int i;
	int A[11] = {0 ,1,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};
	printf("\n");
	for(i = 0;i <= 10; i++)
		printf("%d\t",A[i]);
	printf("Doing Heap Sort\n");
	HeapSort(A);
	printf("\n");
	for(i = 0;i <= 10; i++)
		printf("%d\t",A[i]);
}