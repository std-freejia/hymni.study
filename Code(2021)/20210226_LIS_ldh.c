#include <stdio.h>

//ldh, LIS, 백준 11053

int main(int argc, char* argv[], char* env[])
{
	int length = 0;
	int input[1000] = {0,};
	int dp[1000] = {0,};
	int min, max = 0;
	
	scanf("%d", &length);
	
	for(int i = 0; i < length; i++)
	{
		scanf("%d", &input[i]);
		
		dp[i] = 1;
		min = 0;
		
		for(int j = 0; j < i; j++)
		{
			if(input[i] > input[j] && min < dp[j])
			{
				min = dp[j];
			}
		}
		
		dp[i] = min + 1;
		if(max < dp[i])
		{
			max = dp[i];
		}
	}
	
	printf("%d\n", max);

	return 0;
}

/*
input[] = {10 20 10 30 20 50}
dp[]	= {1  2  1  3  2  4 }
답-> dp[5] = 4
dp[i] = max(dp[i] + 1) (1<=j<i, Aj<Ai)
*/