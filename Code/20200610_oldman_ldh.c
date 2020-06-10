#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	int time = 0;
	//char alphabet[100] = {0,};
	char *alphabet = malloc(sizeof(char) * 100);

	printf("Enter the Dial Alphabet : ");
	scanf("%s", alphabet);

//	printf("test %c", alphabet[1]);
	//printf("test2 %ld\n", strlen(alphabet));
	//printf("test3 %ld\n", sizeof(alphabet)/sizeof(char));

	for(int i = 0; i < strlen(alphabet); i++)
	{
		if(alphabet[i] == 'A' || alphabet[i] == 'B' || alphabet[i] == 'C')
		{
			time += 3;
		}
		else if(alphabet[i] == 'D' || alphabet[i] == 'E' || alphabet[i] == 'F')
		{
			time += 4;
		}
		else if(alphabet[i] == 'G' || alphabet[i] == 'H' || alphabet[i] == 'I')
		{
			time += 5;
		}
		else if(alphabet[i] == 'J' || alphabet[i] == 'K' || alphabet[i] == 'L')
		{
			time += 6;
		}
		else if(alphabet[i] == 'M' || alphabet[i] == 'N' || alphabet[i] == 'O')
		{
			time += 7;
		}
		else if(alphabet[i] == 'P' || alphabet[i] == 'Q' || alphabet[i] == 'R' || alphabet[i] == 'S')
		{
			time += 8;
		}
		else if(alphabet[i] == 'T' || alphabet[i] == 'U' || alphabet[i] == 'V')
		{
			time += 9;
		}
		else if(alphabet[i] == 'W' || alphabet[i] == 'X' || alphabet[i] == 'Y' || alphabet[i] == 'Z')
		{
			time += 10;
		}
		else
		{
			time += 2;
		}	
	}

	printf("Dial Time : %d\n", time);

	free(alphabet);

	return 0;
}
