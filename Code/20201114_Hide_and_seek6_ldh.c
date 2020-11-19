#include <stdio.h>
#include <stdlib.h>

//BAEKJOON 17087, 숨바꼭질6, LDH

int gcd(int a, int b);

int main(int argc, char* argv[], char* env[])
{
	int N = 0;	//동생의 수
	int S = 0;	//수빈의 위치
	int n = 0;	//동생의 위치
	int *buffer;
	int result = 0;
	int diff = 0;	//절대값 저장
	
	scanf("%d %d", &N, &S);
	buffer = (int*)malloc(sizeof(int)*N);	//동생의 수만큼 buffer 동적할당
	for(int i=0; i<N; i++)
	{
		scanf("%d", &n);
		
		diff = S - n;	//수빈의 위치 - 입력받은 동생의 위치
		if(diff < 0)
		{
			diff = -diff;	//절대값으로 저장
		}
		buffer[i] = diff;	//버퍼에 저장
	}
	
	result = buffer[0];		//
	
	for(int i=1; i<N; i++)
	{
		result = gcd(result, buffer[i]);	//최대공약수 저장
	}
	
	free(buffer);
	
	printf("%d", result);

	return 0;
}

int gcd(int a, int b)
{
	int temp = 0;
	
	while(b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	
	return a;
}