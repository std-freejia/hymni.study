#include <stdio.h>
#include <stdlib.h>

//BAEKJOON 2004, The Number of 0s(조합 0의 개수), LDH

int countFiveTwo(int, int);

int main(int argc, char* argv[], char* env[])
{
	int n, m = 0;
	int five, two = 0;
	int result = 0;
	
	scanf("%d %d", &n, &m);
	
	//m이 n보다 클 경우 처리
	if(m > n)
	{
		fprintf(stderr, "Wrong input\n");
		exit(EXIT_FAILURE);
	}
	
	//n! / (n-m)!*m! 연산
	//5와 2중에 적은 개수를 가지고 있는 것이 최종 끝자리에 나오는 0의 개수 의미
	//끝자리에 0이 나온다는 것이 2x5의 조합으로 만들어지기 때문에
	five = countFiveTwo(1, n) - countFiveTwo(1, m)- countFiveTwo(1, n-m);
	two = countFiveTwo(2, n) - countFiveTwo(2, m) - countFiveTwo(2, n-m);
	
	//5의 개수와 2의 개수 중 적은 수를 출력하기 위해 최소값 찾기
	if(two > five)
	{
		result = five;
	}
	else
	{
		result = two;
	}

	//결과 출력
	printf("%d\n", result);

	return 0;
}

//2와 5의 개수를 찾는 함수, flag==1 -> 5찾기, flga==2 -> 2찾기
int countFiveTwo(int flag, int temp)
{
	int res = 0;
	
	if(flag == 1)
	{
		for(long i=5; temp/i > 0; i*=5)
		{
			res += temp/i;
		}
	}
	else if(flag == 2)
	{
		for(long i=2; temp/i > 0; i*=2)
		{
			res += temp/i;
		}
	}
	
	return res;
}