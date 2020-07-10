#include <stdio.h>
#include <stdlib.h>

//ldh
//Seven Dwarf, BAEKJOON 2309

int cal(int integer);

int main(int argc, char *argv[], char *env[])
{
	int testcase = 0;
	int input = 0;
	
	if(0 < input && input < 11)
	{
		fprintf(stderr, "input value not correct");
		exit(EXIT_FAILURE);
	}
	
	scanf("%d", &testcase);
	
	for(int i = 0; i < testcase; i++)
	{
		scanf("%d", &input);
		cal(input);
	}

	return 0;
}

int cal(int integer)
{
	int combination[11] = {0,};
	
	combination[0] = 1;
	combination[1] = 1;
	combination[2] = 2;
	combination[3] = 4;
	
	if(integer < 4)
	{
		printf("%d\n", combination[integer]);
	}
	else
	{
		for(int i = 4; i <= integer; i++)
		{
				combination[i] = combination[i-3] + combination[i-2] + combination[i-1];
		}
		printf("%d\n", combination[integer]);
	}
	
	return 0;
}