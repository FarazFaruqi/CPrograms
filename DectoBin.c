#include <stdio.h>
#include <stdlib.h>

void Convert(int a)
{
	if(a == 0)
		return;
	else
	{
		Convert(a/2);
		printf("%d", a%2);
	}
}

/*int main()
{
	int n;
	printf("Enter the number\n");
	scanf("%d", &n);
	Convert(n);
	printf("\n\n");
}*/
