#include <stdio.h>
#include <stdlib.h>

//BAEKJUN 14500, Tetromino, LDH, 200903

int paper[500][500];

int search(int, int, int);
int findMax(int, int);

int main(int argc, char* argv[], char* env[])
{
	int width = 0;	//width
	int height = 0;	//height

	int result = 0;	//maximum value

	scanf("%d %d", &width, &height);
	
	if(width < 4 || height < 4 || width > 500 || height > 500)
	{
		printf("Input Value Error");
		exit(1);
	}

	//make 2dimension array -> paper
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++){
			scanf("%d", &paper[i][j]);
		}
	}

	result = search(width, height, result);

	printf("%d\n", result);

	return 0;
}

int search(int width, int height, int result)
{
	int tmp = 0;

	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			//I mino
			if(i + 3 < width)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+3][j];
				result = findMax(result, tmp);
			}
			if(j + 3 < height)
			{
				tmp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];
				result = findMax(result, tmp);
			}

			//L mino
			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1];
				result = findMax(result, tmp);
			}

			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1] + paper[i+2][j];
				result = findMax(result, tmp);
			}

			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i][j+1];
				result = findMax(result, tmp);
			}

			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
				result = findMax(result, tmp);
			}

			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2];
				result = findMax(result, tmp);
			}

			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j];
				result = findMax(result, tmp);
			}

			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
				result = findMax(result, tmp);
			}

			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+2];
				result = findMax(result, tmp);
			}
			
			//O mino
			if(i + 2 <= width && j + 2 <= height)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1];
				result = findMax(result, tmp);
			}

			//T mino
			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+1];
				result = findMax(result, tmp);
			}
			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1];
				result = findMax(result, tmp);
			}
			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+1][j+1];
				result = findMax(result, tmp);
			}
			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
				result = findMax(result, tmp);
			}
			
			//S mino
			if(i + 2 <= width && j + 3 <= height)
			{
				tmp = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j+2];
				result = findMax(result, tmp);
			}
			if(i + 2 <=width && j + 3 <= height)
			{
				tmp = paper[i+1][j] + paper[i+1][j+1] + paper[i][j+1] + paper[i][j+2];
				result = findMax(result, tmp);
			}
			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j+1];
				result = findMax(result, tmp);
			}
			if(i + 3 <= width && j + 2 <= height)
			{
				tmp = paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j];
				result = findMax(result, tmp);
			}
		}
	}
		
	return result;
}

int findMax(int value1, int value2)
{
	int max = 0;

	if(value1 >= value2)
	{
		max = value1;
	}
	else
	{
		max = value2;
	}
	
	return max;
}