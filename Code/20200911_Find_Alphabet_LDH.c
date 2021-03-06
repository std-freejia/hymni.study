#include <stdio.h>
#include <string.h>

//BAEKJOON 10908, Find Alphabet, LDH 200918

int main(int argc, char* argv[], char* env[])
{
	char S[100] = {NULL,};	//입력 문자열 담을 배열
	int alpha[26] = {0,};		//알파벳 26개
	
	scanf("%s", S);
	
	/*
	//이전 코드 -> 이중for문 사용
	for(int i = 'a'; i <= 'z'; i++)	//소문자 a 10진수 -> 97, z -> 122
	{
		for(int j = 0; j < 100; j++)
		{
			//a-z 체크
			if(S[j] == i)
			{
				alpha[i-97] = j + 1;
				break;
			}
		}
	}
	*/
	
	for(int i = 0; i < strlen(S); i++)	//소문자 a 10진수 -> 97, z -> 122
	{
		//a-z 체크
		if(alpha[S[i] - 97] == 0)
		{
			alpha[S[i]-97] = i + 1;
		}
	
	}
	
	for(int i = 0; i < 26; i++)
	{
		printf("%d ", alpha[i] - 1);
	}

	return 0;
}
