#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int n;
	struct node* next;
}node;

node* insert(node* list, int val, int loc );
node* delete(node* list, int val);
node* append(node* list, int val);
node* display(node* list);
int size(node* list);
node* sort(node* list, int n);

int main()
{
	node* list;
	list = (node*)malloc(sizeof(node*));
	list->next = NULL;
	printf("\n\nThe list is currently empty\n");
	int flag = 1;
	int i,n, pos, val, m;
	printf("\n\nDiscover the beauty of Linked List!!\n\n");
	while(flag != 0)
	{
		printf("\n\n1 for insertion\n2 for deletion\n3 for appending\n4 for the size of the current list'\n5 for displaying the list\n");
		printf("6 for sorting the array\n7 for exiting the procedure\n\n\nEnter the choice ::");

		scanf("%d", &n);

		if(n == 7)
			flag = 0;

		else if(n == 1)
		{
			
			printf("Enter the value you want to enter\n");
			scanf("%d", &val);
			printf("Enter the position you want to enter in\n");
			scanf("%d", &pos);
			list = insert(list, val, pos-1);
			printf("The value was entered!!\n\n");
			list = display(list);

		}

		else if(n == 2)
		{
			if(list->next == NULL)
			{
				printf("the list is empty\n");
				continue;
			}
			printf("Enter the value you want to be deleted\n");
			scanf("%d", &val);
			list = delete(list,val);
			//printf("The value was deleted!!\n");
		}

		else if(n == 3)
		{
			

			printf("Enter the number of values you want to enter\n");
			scanf("%d", &m);
			for(i = 0; i< m; i++)
			{
				printf("Enter the value to be appended!\n");
				scanf("%d", &val);
				list = append(list, val);
			}
		}
		else if(n == 5)
		{
			if(list->next == NULL)
			{
				printf("the list is empty\n");
				continue;
			}
			printf("Here's your linked list\n");
			list = display(list);
			
		}
		else if(n == 6)
		{
			int s = size(list);
			printf("Here is the sorted list\n");
			list = sort(list,s);

			list = display(list);
		}

		else if(n == 4)
		{
			//printf("The size of the current linked list\t");
			int f = size(list);
			if(f == 0)
				printf("The list is empty. Please insert some values\n");
			else
				printf("The size of the list is %d", f);
		}
		else
			printf("Wrong choice entered\t Enter 1, 2, 3, 4, 5, 6 \n\n");

	}
	return 0;
}

node* insert(node* list, int val, int loc)
{
	int i, flag = 0, c = 0;
	node* first = list;
	while(list->next != NULL)
	{	
		c++;
		if(c == loc)
		{
			flag = 1;
			break;
			
		}
		list = list->next;
	}
	if(flag == 1)
	{
		node* app;
		app = (node*)malloc(sizeof(node*));
		app->next = list->next;
		app->n = val;
		list->next = app;
	}
	else
		printf("Not that many elements\n");
	return first;
}

node* delete(node* list, int val)
{
	
	node* first = list;
	node* prev;
	int i,flag = 0, c = 1;
	while(list->next != NULL)
	{
		if(list->n == val)
		{
			flag = 1;
			break;
		}
		prev = list;
		list = list->next;
	}
	if(flag == 1)
	{
		prev->next = list->next;
		list = NULL;
		printf("The value was found and deleted!\n");
	}
	else
		printf("Enter an existing value\n");
	return first;
}

node* append(node* list,int val)
{
	node* first = list;
	int i, flag = 0;
	while(list->next != NULL)
	{
		list = list->next;
	}
	node *app;
	app = (node*)malloc(sizeof(node*));
	list->next = app;
	app->next = NULL;
	app->n = val;
	printf("Appended!\n");
	return first;
}

int size(node* list)
{
	int c = 0;
	while(list->next != NULL)
	{
		list = list->next;
		c++;
	}
	return c;
}
node* display(node* list)
{
	node* first = list;
	int c = 0;
	while(list->next != NULL)
	{
		printf("%d\t",list->n);
		list = list->next;
		c++;
	}
	if(c == 0)
		printf("The linked list was empty\n");
	return first;
}
node* sort(node* list,int n)
{
	int temp;
	node* first = list; 
	int c = 0;
	node* go = list;
	node* max;
	printf("Trying to print the list\n");
	while(list->next != NULL)
	{
		go = list;
		max = list;
		while(go->next != NULL)
		{
			if(max->n < go->n)
				max = go;
			go = go->next;
		}
		temp = max->n;
		max->n = list->n;
		list->n = temp;
		list = list->next;
		c++;
	}
	return(first);
}
