#include <stdio.h>
#include <math.h>

//ldh
//BAEKJOON 9934, Complete Binary Tree

int tree[1024] = {0,};
int depth = 0;

int main(int argc, char *argv[], char *env[])
{
	int idx = 0;
	int idy = 0;
	
	scanf("%d", &depth);
	
	for(idx = 0; idx < pow(2, depth); idx++)
	{
		scanf("%d", &tree[idx]);
	} 
	
	for(idx = depth; idx >= 1; idx--)
	{
		for(idy = (pow(2, idx-1) - 1); idy < pow(2, depth); idy += pow(2, idx))
		{
			printf("%d ", tree[idy]);
		}		
		printf("\n");
	}
	
	return 0;
}