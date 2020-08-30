#include <stdio.h>

int main(int argc, char* argv[], char* env[])
{
	int positionOfSubin = 0;	//수빈의 위치
	int positionOfSister = 0;	//동생의 위치
	int Q[250000] = {0, }; 
	int visit[100001] = {0, }; 
	int front = -1;
	int back = -1;
	int d[100001] = {0, };
	
	//수빈 위치, 동생 위치 입력 받음
	scanf("%d %d", &positionOfSubin, &positionOfSister);
	
	//두 위치가 같을 경우 종료
	if(positionOfSubin == positionOfSister)
	{
		printf("0");
		return 0;
	}
	
	Q[++back] = positionOfSubin;
	
	while(front != back)
	{
		front++;
		
		//x-1, x+1, x*2 세가지 이동
		
		//x*2 이동
		if(visit[Q[front] * 2] == 0 && (Q[front] * 2) < 100001 && (Q[front] * 2 >= 0))
		{
				Q[++back] = Q[front] * 2;
				d[back] = d[front] + 1;
				visit[Q[back]] = 1;
		}
		//동생 찾는 경우
		if(Q[back] == positionOfSister)
		{
			break;
		}
		
		//x-1 이동
		if(visit[Q[front] - 1] == 0 && (Q[front] - 1<100001) && (Q[front] -1 >= 0))
		{
			Q[++back] = Q[front] - 1;
			d[back] = d[front] + 1;
			visit[Q[back]] = 1;
		}
		//동생 찾는 경우
		if(Q[back] == positionOfSister)
		{
			break;
		}
		
		//x+1 이동
		if(visit[Q[front] + 1] == 0 && (Q[front] + 1<100001) && (Q[front] +1 >= 0))
		{
			Q[++back] = Q[front] + 1;
			d[back] = d[front] + 1;
			visit[Q[back]] = 1;
		}
		//동생 찾는 경우
		if(Q[back] == positionOfSister)
		{
			break;
		}
	}
	
	printf("%d", d[back]);
	
	return 0;
}