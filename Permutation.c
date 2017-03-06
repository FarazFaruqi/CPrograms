#include <sdio.h>
#include <string.h>
void Permute(char str[],char rem[])
{
	if(strlen(str) == 0)
	{
		printf("%s",rem);
		return;
	}
	else
	{
		int i;
		for(i = 0;i < strlen(str);i++)
		Permute(str[i],)
	}
}