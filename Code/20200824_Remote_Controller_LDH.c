#include <stdio.h>

int check(int k, int broken[]);

int main(int argc, char* argv[], char* env[])
{
	int broken[11] = {0,};	//리모컨의 버튼(값 -> 0 : 정상 / 값 -> 1 :고장)
	int num_1 = 0;	//goal - 100, 이동횟수
	int num_2 = 0;	//
	int numberOfBrokenButton = 0;	//망가진 버튼의 개수
	int goal = 0;	//이동하려고하는 채널
	int min = 1000000;
	int length = 0;
	int l = 0;

	scanf("%d %d", &goal, &numberOfBrokenButton);	//이동하려는 채널과 망가진 버튼의 개수 입력 받음
	num_1 = goal - 100;
	
	//이동하려는 채널 - 100(현재채널 번호)가 음수일 경우 처리
	if(num_1 < 0)
	{
		num_1 = -1 * num_1;
	}
	
	//망가진 리모컨 번호 입력받고 broken배열 인덱스를 1로 수정
	for(int i = 0; i < numberOfBrokenButton; i++)
	{
		int k = 0;
		scanf("%d", &k);
		broken[k] = 1;	//0: 정상, 1: 고장
	}
	
	//이동하고자하는 채널의 수 500000 -> 고장난 버튼 
	for(int i = 0; i < 1000001; i++)
	{
		length = check(i, broken);
		if(length)
		{
			int k = goal - i;
			if(k<0)
			{
				k = k * -1;
			}
			if(k < min)
			{
				min = k;
				l = length;
			}
		}
	}
	
	num_2 = min + l;
		
	printf("%d", num_1<num_2?num_1:num_2);
	
	return 0;
}

int check(int k, int broken[])
{
	int length = 0;
	if(k == 0)
	{
		return broken[0] ? 0 : 1;
	}
	
	while(k)
	{
		length++;
		if(broken[k%10])
		{
			return 0;
		}
		k /= 10;
	}
	
	return length;
}