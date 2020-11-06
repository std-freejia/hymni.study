#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BAEKJOON 11656, 접미사 배열, LDH

int compare(const void *a, const void *b);

int main(int argc, char* argv[], char* env[])
{
	char string[1000];
	
	scanf("%s", string);
	
	int size = strlen(string);
	char temp[size][1000];

	//입력값 앞자리 하나씩 잘라주면서 temp배열에 저장
	for(int i = 0; i < size; i++)
	{
		strncpy(temp[i], string+i, size-i);
	}
		
	//퀵정렬 이용해서 문자열 정렬
	qsort(temp, sizeof(temp)/sizeof(temp[0]), sizeof(temp[0]), compare);
	
	//정렬된 temp배열 출력
	for(int i = 0; i < size; i++)
	{
		printf("%s\n", temp[i]);
	}
	
	return 0;
}

// 오름차순 비교 함수 구현
int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}
