#include <stdio.h>
#include <stdlib.h>

//ldh
//brute force algorithms

int sum = 0;

int discovery(int **map, int row, int col, int n, int routeSum)
{
	routeSum += map[row][col];
	//printf("routeSum : %d\n", routeSum);	//routeSum total value each recursive function

	if(row == n - 1 && col == n - 1)
	{
		if(sum < routeSum)
		{
			sum = routeSum;
		}
		routeSum = 0;
		return 0;
	}

	if(row + 1 < n)
	{
		//printf("map : %d %d\n", row, col);	//current map[row][col]
		discovery(map, row + 1, col, n, routeSum);
	}

	if(col + 1 < n)
	{
		//printf("map : %d %d\n", row, col);	//current map[row][col]
		discovery(map, row, col + 1, n, routeSum);
	}

	return sum;
}

int main(int argc, char *argv[], char *env[])
{
	int input = 0;

	scanf("%d", &input);

	//memory allocation
	int **map = malloc(sizeof(int *) * input);

	for(int i = 0; i < input; i++)
	{
		map[i] = malloc(sizeof(int) * input);
	}

	//enter the array input by user
	for(int i = 0; i < input; i++)
	{
		for(int j = 0; j < input; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//recursive function
	printf("result : %d\n", discovery(map, 0, 0, input, 0));


	//memoey free
	for(int i = 0; i < input; i++)
	{
		free(map[i]);
	}
	free(map);


	return 0;
}
