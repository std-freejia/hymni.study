#include <stdio.h>
#include <string.h>

//BAEKJOON 2529, 부등호, LDH

int swap(int a, int b);
int bf(int flag, int n);
int check();

char str[10], max[10], min[10], copy[10] = {0,};

int main()
{
	//부등호 개수 k, 부등호 모음 str배열에 입력받고 저장
	int k = 0;
	int i = 0;
	scanf("%d", &k);
	
	for(i = 0; i <= k; i++)
	{
		if(i != k)
		{
			getchar();
			str[i] = getchar();
		}
		else
		{
			str[i] = NULL;
		}
		
		//최대값, 최소값을 구하는 수 모음을 한정
		max[i] = '9' - k + i;	//ex) k==3, max=789
		min[i] = '0' + k - i;	//ex) k==3, min=210
	}
	
	max[i] = NULL;
	min[i] = NULL;

	//최대값 재귀함수 동작(flag == 1)
	strcpy(copy, max);
	bf(1, k + 1);
	//최소값 재귀함수 동작(flag == 0)
	strcpy(copy, min);
	bf(0, k + 1);
	
	printf("%s\n%s", max, min);
    
	return 0;
}

//최대값, 최소값을 구하기 위해 자리바꾸기 함수
int swap(int a, int b)
{
	char tmp;
	
	tmp = copy[a];
	copy[a] = copy[b];
	copy[b] = tmp;
	
	return 0;
}

int bf(int flag, int n)
{
	//부등호 맞게 동작하는지 check함수로 확인
	if(check())
	{
		if(flag)	//flag == 1 -> 최대값 찾기, flag == 0 -> 최소값 찾기
		{
			if(strcmp(max, copy) < 0)	//copy가 클 경우 if문 진입
			{
				strcpy(max, copy);	//최대값을 max에 복사
			}
		}
		else{
			if(strcmp(min, copy) > 0)	//copy가 작을 경우 if문 진입
			{
				strcpy(min, copy);	//최소값을 min에 복사
			}
		}
	}
	
	
	for(int i = 0; i < n; i++)
	{
		//swap함수로 자리 교환 후 재귀함수 돌려보고 맞으면 max또는 min에 저장, 틀리면 다시 제자리로 swap
		swap(i, n - 1);
		bf(flag, n - 1);
		swap(i, n - 1);
	}
	
	return 0;
}

//입력받은 부등호에 따른 정상 연산을 하는지 확인, 아닐 경우 return 0 -> 다음 수 비교
int check()
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '<')
		{
			if(copy[i] >= copy[i + 1])
			{
				return 0;
			}
		}
		else if(str[i] == '>')
		{
			if(copy[i] <= copy[i + 1])
			{
				return 0;
			}
		}
	}

	return 1;
}