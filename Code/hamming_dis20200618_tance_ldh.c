#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//LDH, 200623
//Hamming Distance

int hammingDist(char *input1, char *input2);

int main(int argc, char *argv[], char *env[])
{
	int count = 0;
	char input1[100] = {0,};
	char input2[100] = {0,};

	scanf("%d", &count);
	getchar();

	for(int i = 0; i < count; i++)
	{
		fgets(input1, 100, stdin);
		input1[strlen(input1) - 1] = '\0';
		fgets(input2, 100, stdin);
		input2[strlen(input2) - 1] = '\0';

		printf("Hamming distance is %d.\n", hammingDist(input1, input2));
	}
/*
	for(int i=0;i<strlen(input1);i++){
		printf("input1[%d] : %c\n", i, input1[i]);
	}

	for(int i=0;i<strlen(input2);i++){
		printf("input2[%d] : %c\n", i, input2[i]);
	}
*/
	return 0;
}

int hammingDist(char *input1, char *input2)
{
	int i = 0;
	int result = 0;

	while(input1[i] != '\0')
	{
		if(input1[i] != input2[i])
		{
			result++;
		}
		i++;
	}

	return result;
}
