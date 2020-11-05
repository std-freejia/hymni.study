#include <stdio.h>
//#include <math.h>	//pow, sqrt 연산 사용

//BAEKJOON 1699, 제곱의 합, LDH

//최소값 함수(삼항연산자 외워서 사용할 것)
int min(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char* argv[], char* env[])
{
	//math.h정의된 sqrt함수(루트연산), pow함수 사용 실패 -> 최소항 개수 불만족(ex.input 43)
	/*
	int input = 0;
	int count = 2147483647;
	
	scanf("%d", &input);
	
	int inputTemp = input;
	int countTemp = 0;
	
	for(int i = sqrt(input); 0 < i; i--)
	{
		while(1)
		{
			countTemp++;
			inputTemp -= pow(sqrt(inputTemp), 2);
			if(inputTemp == 0)
			{
				break;
			}
		}
		if(countTemp < count)
		{
			count = countTemp;
		}
		
	}
	
	printf("%d\n", count);
	*/

	int input = 0;
	int d[100000] = {0,};	//인덱스 -> input값, 해당 인덱스의 값 -> 인덱스값을 구성하는 최소항 제곱의 합 개수
	
	scanf("%d", &input);
	
	//i라는 수가 1^2이 몇개 필요한지 배열에 저장
	for (int i = 0; i <= input; i++)
	{
		d[i] = i;
	}
	
	//d배열을 업데이트 해나감 -> 들어가는 값이 곧 최소항으로 필요한 제곱수의 개수
	for (int i = 2; i <= input; i++)
	{
		for (int j = 2; j*j <= i; j++)	//
		{
			d[i] = min(d[i], d[i - j*j] + 1);	//+1해주는 이유 -> j*j연산이 이미 한번 수행했기 때문에
		}
	}
	
	printf("%d\n", d[input]);

	return 0;
}

/*
EX) input = 43
2^2+6^2+1^2+1^2+1^2 -> 5개
3^2+5^2+3^2			-> 3개(정답)
4^2+5^2+1^2+1^2		-> 4개
5^2+3^2+3^2			-> 3개(정답)
6^2+2^2+1^2+1^2+1^2 -> 5개
*/