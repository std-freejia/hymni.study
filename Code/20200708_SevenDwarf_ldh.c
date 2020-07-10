#include <stdio.h>
#include <stdlib.h>

//ldh
//BAEKJOON 2309, seven dwarf

int dwarf[9] = {0,};
int totalHeight[7] = {0,};
int flag = 0;

int selectHeight(int numberOfDwarf, int sumOfDwarf, int idx);	//함수 원형 선언

int main(int argc, char *argv[], char *env[])
{
	int temp = 0;
	
	//입력
	for(int idx = 0; idx < 9; idx++)
	{
		scanf("%d", &dwarf[idx]);
	}
	
	//재귀함수 호출
	selectHeight(0, 0, 0);
	
	//오름차순 출력이기 때문에 전역변수 totalHeight을 버블 정렬
	for(int idx = 6; idx > 0; idx--)
	{
		for(int idy = 0; idy < idx; idy++)
		{
			if(totalHeight[idy] > totalHeight[idy+1])
			{
				temp = totalHeight[idy];
				totalHeight[idy] = totalHeight[idy+1];
				totalHeight[idy+1] = temp;
			}
		}
	}
	
	//출력 결과 표시
	for(int idx = 0; idx < 7; idx++)
	{
		printf("%d\n", totalHeight[idx]);
	}

	return 0;
}

int selectHeight(int numberOfDwarf, int sumOfDwarf, int idx)
{
	//재귀함수 base case 설정
	if(numberOfDwarf == 7)
	{
		if(sumOfDwarf == 100)
		{
			flag = 1;
			return 0;
		}
		else
		{
			return 0;
		}
	}
	
	for(int i = idx; i < 9; i++)
	{
		totalHeight[numberOfDwarf] = dwarf[i];
		selectHeight(numberOfDwarf + 1, sumOfDwarf + totalHeight[numberOfDwarf], i + 1);
		if(flag == 1)
		{
			return 0;
		}
	}
	
	return 0;
}