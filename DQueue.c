#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef enum BOOL
{
	FALSE,TRUE
}BOOL;
#define INFINITY -9999

typedef struct{
	int front,rear;
	int a[SIZE];

}DQueue;
void insertLeft(DQueue* q,int item);
int DeleteLeft(DQueue* q);
void insertRight(DQueue* q,int item);
int DeleteRight(DQueue* q);
void display(int* queue);
BOOL isEmpty(DQueue q);
BOOL isFull(DQueue q);

int main()
{
	int i,flag=0,g,h,j,n,c;
	DQueue l;
	l.front = 0;
	l.rear = -1;
	do
	{
		printf("\n\nWelcome to DQueue classes!!\n Enter 1 for insertion\nEnter 2 for deletion\n Enter 3 for displaying the array\nEnter 4 for exiting\n\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the number you want to insert\n");
				scanf("%d",&i);
				printf("Enter the side 1 for left 2 for right\n");
				scanf("%d",&c);
				if(c == 1)
				insertLeft(&l,i);
				else
					insertRight(&l,i);
				break;
			case 2:
			printf("Enter the side 1 for left 2 for right\n");
				scanf("%d",&c);
				if(c == 1)
					DeleteLeft(&l);
				else
					DeleteRight(&l);
				if(g != INFINITY)
					printf("The deleted element  %d\n", g);
				break;
			case 3:
				display(l.a);
				break;
			case 4:
				flag = 1;
				break;
			default:
				printf("Wrong Choice\n");
		}

	}while(flag == 0);
	return 0;

}


void insertRight(DQueue* q,int item)
{
	if(q->rear == SIZE - 1)
	{
		printf("THE QUEUE IS FULL\n");
		return;
	}
	q->a[++q->rear] = item;
}
int DeleteRight(DQueue* q)
{
	if(!isEmpty(*q))
		return(q->a[q->rear--]);
}

void insertLeft(DQueue* q,int item)
{
	if(q->front == 0 && q->rear ==-1)
		q->a[++q->rear] = item;

	else if(q->front == 0)
	{
		printf("The queue is full\n");
		return;
	}
	else
		q->a[--q->front] = item;

}

int DeleteLeft(DQueue* q)
{
	if(!isEmpty(*q))
	return q->a[q->front++];
}

void display(int* queue)
{
	int i;
	for(i = 0;i < SIZE;i++)
	{
		if(*(queue + i) == 0)
		{
			printf(" _ ");
			continue;
		}
		else
			printf(*(queue + i)+ "  ");

	}
}

BOOL isEmpty(DQueue q)
{
	if(q.front > q.rear)
		return TRUE;
	return FALSE;
}

BOOL isFull(DQueue q)
{
	if(q.front == 0 && q.rear == SIZE-1)
		return TRUE;
	return FALSE;
}