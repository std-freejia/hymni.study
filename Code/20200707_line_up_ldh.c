#include <stdio.h>
#include <stdlib.h>

//ldh
//baekjoon 2631

int main(int argc, char *argv[], char *env[])
{
	int numberOfKids = 0;
	int idx, idy = 0;
	int max = 0;
	int kidsSequence[200] = {0,};
	int sortSequence[200] = {0,};

	scanf("%d", &numberOfKids);
	for(idx = 1; idx <= numberOfKids; idx++)
	{
		scanf("%d", &kidsSequence[idx]);
	}

	for(idx = 1; idx <= numberOfKids; idx++)
	{
		sortSequence[idx] = 1;
		for(idy = 1; idy < idx; idy++)
		{
			if(kidsSequence[idy] < kidsSequence[idx] && sortSequence[idx] < sortSequence[idy] + 1)
			{
				sortSequence[idx]++;
			}
		}

		if(max < sortSequence[idx])
		{
			max = sortSequence[idx];
		}
	}

	printf("%d", numberOfKids-max);

		
	
	return 0;
}
