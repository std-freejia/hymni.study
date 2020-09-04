#include <stdio.h>
#include <string.h>

//BAEKJUN 14501, Resignation(퇴사), 200903

//구조체 선언(상담 소요일 T, 임금 P)
typedef struct
{
	int T, P;
}TimeAndPay;

int N;		//남은 재직 기간
int MAX;	//최대 이익을 담을 변수

TimeAndPay TP[16];

int search(int, int);	//재귀 함수 선언

int main(int argc, char* argv[], char* env[])
{
	/* 입력 처리 부분 시작 */
	scanf("%d", &N);
	MAX = -1;
	
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &TP[i].T, &TP[i].P);
	}
	/* 입력 처리 부분 끝 */
	
	search(0, 0);
	
	printf("%d", MAX);

	return 0;
}

//recursive func.
int search(int cur, int total)
{
	//최대값 MAX에 저장
	if(total > MAX)
	{
		MAX = total;
	}
	
	for(int i = cur + 1; i <= N; i++)
	{
		if(i + TP[i].T - 1 > N)
		{
			continue;
		}
		
		search(i + TP[i].T - 1, total + TP[i].P);
	}
	
	return 0;		
}