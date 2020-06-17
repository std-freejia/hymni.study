#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	int input = 0;
	int sum = 1;
	char str[100] = {0,};
	int size = 0;
	int result = 0;

	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &input);
		sum *= input;
	}

	sprintf(str, "%d", sum);

	size = strlen(str);

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if((int)str[j]-48 == i)
			{
				result += 1;
			}
		}

		printf("%d\n", result);
		result = 0;
	}

	return 0;
}
