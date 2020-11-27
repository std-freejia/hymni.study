#include <stdio.h>
#include <stdlib.h>

//BAEKJOON 15650, N과 M(2), LDH

int solve(int, int);

int n = 0;	//n까지의 수 범위지정
int m = 0;	//m개 선택
int arr[10];		//수열을 저장
int check[10];		//초기값 0, 수열을 만드는데 사용한 수인지 판단

int main(int argc, char* argv[], char* env[])
{	
	scanf("%d %d", &n, &m);
	
	//입력값 확인
	if(m > n || n > 8 || 1 > m)
	{
		fprintf(stderr,"Input Value Error\n");
		exit(1);
	}
	
	solve(0, 1);

	return 0;
}

int solve(int cnt, int cur)
{
    if(cnt == m)
	{
		//m값과 재귀횟수가 같으면 arr배열에 저장된 수열 출력(오름차순으로 출력)
        for(int i=0; i<m; i++)
		{
            printf("%d ", arr[i]);
		}
        printf("\n");
        
		return 0;
    }
    
    for(int i=cur; i<=n; i++)
	{
        if(!check[i])
		{
            check[i] = 1;
            arr[cnt] = i;		//arr배열에 수열 저장
            solve(cnt+1, i+1);	//solve함수 재귀동작
            check[i] = 0;	//재귀가 끝나면 check배열 초기화
        }
    }
	
	return 0;
}