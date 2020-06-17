#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 15

int main(int argc, char *argv[], char *env[])
{
	char input[MAX_LENGTH] = {0, };
	char output[MAX_LENGTH * 5] = {0, };
	int inputLength = 0;

	for(int i = 0; i < 5; i++)
	{
		printf("Enter the Input : ");
		fgets(input, MAX_LENGTH, stdin);
		inputLength = strlen(input);
		for(int j = 0; j < inputLength; j++)
		{
			output[i + (j * 5)] = input[j];
		}
	}

	printf("Result : ");
	for (int i = 0; i < inputLength * 5; i++)
	{
		if(output[i] != '\n')
		{
			printf("%c", output[i]);
		}
		else
		{
			continue;
		}
	}
	printf("\n");

	return 0;
}
