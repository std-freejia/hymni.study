#include <stdio.h>

//ldh, 약수의 합2, 백준 17427

int main(int argc, char* argv[], char* env[])
{
	int N = 0;
	long int result = 0;	//최대 1,000,000
	
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
	{
		result += i * (N / i);
		//i번째 수를 N으로 나누면 몇 번 나오는지 계산 가능, (N/i)번 나오므로 i곱하면 더한 값 계산 가능
	}
	
	printf("%ld\n", result);

	return 0;
}

/*
g(N)은 N이하의 각 자연수의 모든 약수를 더한 값
N = 10 일 경우
(1)(1,2)(1,3)(1,2,4)(1,5)(1,2,3,6)(1,7)(1,2,4,8)(1,3,9)(1,2,4,10)

규칙
10/1 = 10 -> 1이 10번
10/2 = 5 -> 2가 5번
...
*/