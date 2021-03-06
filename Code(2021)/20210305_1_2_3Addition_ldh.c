#include <stdio.h>

//ldh, 1 2 3 addition, baekjoon9095

int main(int argc, char* argv[], char* env[])
{
	int testcase = 0;
	int input = 0;
	int arr[11] = {0,};
	
	arr[0] = 1;		//0
	arr[1] = 1;		//1
	arr[2] = 2;		//1+1, 2
	arr[3] = 4;		//1+1+1, 1+2, 2+1, 3
	/*
	arr[4] = 7;
	arr[5] = 13;
	arr[6] = 24;
	arr[7] = 44;
	arr[8] = 81;
	arr[9] = 149;
	arr[10] = 274;
	arr[11] = 504;
	*/
	
	for(int i = 4; i <= 11; i++)
	{
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];	//4이상의 수를 구하는 점화식
	}
	
	scanf("%d", &testcase);

	for(int i = 0; i < testcase; i++)
	{
		scanf("%d", &input);
		
		printf("%d\n", arr[input]);
	}

	return 0;
}