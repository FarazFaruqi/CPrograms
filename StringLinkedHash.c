#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26
typedef enum{FALSE,TRUE}BOOL;

typedef struct node
{
char val[50];
struct node* next;
}node;

typedef struct Hash{
char key;
node* block;
}Hash;

Hash HashArray[SIZE];


int HashCode(char key[])
{
	return (tolower(key[0])-'a');
}
node* allocate(node* n,char val[])
{
	node* list = (node*)malloc(sizeof(node));
	list->next = NULL;
	while(n->next != NULL)
		n = n->next;
	n->next = list;	
	strcpy(list->val,val);

}
void insert(char val[])
{
	int key = hashCode(val);
	HashArray[key].key = key;
	allocate(HashArray[key].block,val);

}

BOOL search(char val[])
{
	int key = hashCode(val);
	node* list;
	list = HashArray[key].block;
	while(list->next != NULL)
	{
		list = list->next;
		if(strcmp(list->val,val)==0)
			return TRUE;
	}
	return FALSE;
}
void printnum()
{
	int i,c;
	for(i =0;i < SIZE;i++)
	{
		node* list = HashArray[i].block;
		c = 0;
		while(list->next != NULL)
		{
			list = list->next;
			printf("%s\t",list->val);
			c++;
		}
		printf("Number of elements in %c are %d\n\n",i+65,c);
	}
}

int main()
{
	printf("This is a program for running a basic String Hash Table\n");
	int i,n;
	char str[40];
	for(i = 0;i < SIZE;i++)
	{
		HashArray[i].block = (node*)malloc(sizeof(node));
		HashArray[i].block->next = NULL;
	}
	printf("Initialized\nEnter the number of words\n\n");
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{
		printf("Enter %d word::  ",i);
		scanf("%s",str);
		insert(str);
	}
	printnum();
	
	printf("Enter a word to search for in the list ::");
	scanf("%s",str);
	BOOL r = search(str);
	if(r)
		printf("The search was successful!\n");
	else
		printf("The element was not present\n");

	return 0;
		
}


