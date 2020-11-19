#include <stdio.h>

//BAEKJOON 11056, 오르막수, LDH

int main(int argc, char* argv[], char* env[])
{
	int input = 0;
	int arr[1001][10] = {0,};
	int result = 0;
	
	scanf("%d", &input);
	
	//초기화 이유
	for(int i=0; i<10; i++)
	{
		arr[1][i] = 1;
	}
	
	
	for(int i=2; i<=input; i++)
	{
		for(int j=0; j<10; j++)
		{
			int sum = 0;
			
			for(int k=j; k<10; k++)
			{
				sum += arr[i-1][k]%10007;
			}
			
			arr[i][j] = sum%10007;
		}
	}
	
	for(int i=0; i<10; i++)
	{
		result += arr[input][i]%10007;
	}
	
	printf("%d", result%10007);

	return 0;
}