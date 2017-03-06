/* Code to store n values in an AVL Tree.
Created by - Faraz Faruqi.
06-02-2017
Manipal Institute of Technology
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
}Node;

Node* newNode(int key)
{
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->data   = key;
    newN->left   = NULL;
    newN->right  = NULL;
    newN->height = 1;  // new node is initially added at leaf
    return(newN);
}
int max(int a, int b)
{
	return (a > b ? a : b);
}


int heightDiff(Node* node)
{
	if(node == NULL)
		return 0;
	return (height(node->left) - height(node->right));
}

int height(Node* node)
{
	if(node == NULL)
		return 0;
	return node->height;
}

int calcHeight(Node* node)
{
	if(node == 0)
		return 0;
	return( max((height(node->left)),(height(node->right))) + 1);
}

Node* leftRotate(Node* node)
{
	Node* temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node->height = calcHeight(node);
	temp->height = calcHeight(temp);

	return temp;

}

Node* rightRotate(Node* node)
{
	Node* temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	node->height = calcHeight(node);
	temp->height = calcHeight(temp);

	return temp;
}

Node* rightLeft(Node* node)
{
	node->right = rightRotate(node->right);
	node = leftRotate(node->left);
	return node;
}

Node* leftRight(Node* node)
{
	node->left = leftRotate(node->left);
	node = rightRotate(node);

	return node;
}

Node* insertToAVL( Node* node, int data)
{
    //Your code here
    if(node == NULL)
    {
    	Node* temp = newNode(data);
    	return(temp);
    }

    else if(data < node->data)
        node->left = insertToAVL(node->left,data);
    else if(data > node->data)
    	node->right = insertToAVL(node->right,data);
    else
    	printf("duplicate\n");
    //printf("coming here after insertion %d\n", node->data);
    
    node->height = calcHeight(node);

    int h = heightDiff(node);
    int hl = heightDiff(node->left);
    int hr = heightDiff(node->right);
    printf("h = %d %d %d\n", h,hl,hr);

    //Right Rotation 
    if(h == 2 && hl == 1)
    {
    	node = rightRotate(node);
    	printf("Right Rotation\n");
    }
    if(h == 2 && hl == -1)
    {
    	node = leftRight(node);
    	printf("Left Right Rotation\n");
    }

    if(h == -2 && hr == -1)
    {
    	node = leftRotate(node);
    	printf("Left Rotation\n");
    }
    if(h == -2 && hr == 1)
    {
    	node = rightLeft(node);
    	printf("Right Left Rotation\n");
    }
    return node;

}

Node* deleteFromAVL( Node* node, int data)
{
    //Your code here
    if(node == NULL)
    {
    	printf("Value not present\n");
    }
    if(node->data == data)
    	return NULL;

    else if(data < node->data)
        node->left = insertToAVL(node->left,data);
    else if(data > node->data)
    	node->right = insertToAVL(node->right,data);
    else
    	printf("duplicate\n");
    //printf("coming here after insertion %d\n", node->data);
    
    node->height = calcHeight(node);

    int h = heightDiff(node);
    int hl = heightDiff(node->left);
    int hr = heightDiff(node->right);
    printf("h = %d %d %d\n", h,hl,hr);

    //Right Rotation 
    if(h == 2 && hl == 1)
    {
    	node = rightRotate(node);
    	printf("Right Rotation\n");
    }
    if(h == 2 && hl == -1)
    {
    	node = leftRight(node);
    	printf("Left Right Rotation\n");
    }

    if(h == -2 && hr == -1)
    {
    	node = leftRotate(node);
    	printf("Left Rotation\n");
    }
    if(h == -2 && hr == 1)
    {
    	node = rightLeft(node);
    	printf("Right Left Rotation\n");
    }
    return node;

}
void printTree(Node* node)
{
	if(node == NULL)
		return;
	else
	{
		printTree(node->left);
		printf("%d  height = %d\n",node->data , node->height);
		printTree(node->right);
	}
}

int main()
{
	printf("Enter the values to insert. Enter 0 to end\n");
	int n;
	printf("enter root\n");
		scanf("%d",&n);
	Node* tree = newNode(n);
	printf("Enter next value\n");
	scanf("%d",&n);
	while(n != 0)
	{
		tree = insertToAVL(tree,n);
		printf("Enter next value\n");
		scanf("%d",&n);
		
	}

	// Printing in Inorder Traversal
	printf("Printing the AVL Tree with heights\n");
	printTree(tree);

	printf("Enter value to be deleted\t Enter 0 to end\n");
	scanf("%d",&n);

	return 0;
}