#include <stdio.h>

//BAEKJOON 6588, Goldbach, LDH

int arr[1000000];    //소수 확인을 위한 배열

int main(int argc, char* argv[], char* env)
{
	int n = 0;	//입력값
	int prime = 0;

	//arr배열에서 인덱스가 소수가 아닐 경우 1로 변경
	for(int i=2; i*i<=1000000; i++)
	{
		if(arr[i] == 0)
		{
			for(int j=i*i; j<=1000000; j+=i)
			{
				arr[j] = 1;
			}
		}
	}
    
    //arr 인덱스 소수 -> 0
    //arr 인덱스 소수x -> 1

	while(scanf("%d", &n) == 1)	//scanf 리턴값 -> 입력받은 인자의 개수
	{
        //n -> 0이면 입력 종료
		if(n == 0)
		{
			break;
		}
		
		for(int j=2; j<=n; j++)
		{
			if(arr[j] == 0)    //arr의 j 인덱스가 0 -> j는 소수
			{
				prime = n - j;	//j < prime을 만족하기 위해 j먼저 작은 수로 처리
				if(arr[prime] == 0)	//arr의 prime 인덱스가 0 -> prime은 소수
				{
					printf("%d = %d + %d\n", n, j, prime);
					break;
				}
				/*
				else
				{
					printf("Goldbach's conjecture is wrong.\n");
					break;
				}
				*/
			}
			
		}
	}

	return 0;
}