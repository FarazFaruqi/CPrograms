#include <stdio.h>
#include <ctype.h>

#define size 10

void quickSort(int A[],int pivot,int left,int right)
{
	if (left < right)
	{
	int l = left,r = right,p = pivot,temp;
	while(left < right)
	{
		if(A[left] < A[pivot])
			left++;
		if(A[right] > A[pivot])
			right--;
		if(A[left] > A[pivot] && A[right] < A[pivot])
		{
			temp = A[left];
			A[left] = A[right];
			A[right] = temp;
		}
	}
	temp = A[pivot];
	A[pivot] = A[right];
	A[right] = temp;
	printf("Recursice\n");
	quickSort(A,l,l+1,right);
	quickSort(A,right,right+1,r);
}
}

int main()
{
	int i;
	int A[11] = {10 ,9,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1 ,0};
	printf("\n");
	for(i = 0;i <= 10; i++)
		printf("%d\t",A[i]);
	printf("Doing Quick Sort\n");
	quickSort(A,0,1,9);
	printf("\n");
	for(i = 0;i <= 10; i++)
		printf("%d\t",A[i]);
}