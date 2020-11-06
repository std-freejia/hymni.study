#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BAEKJOON 11656, 접미사 배열, LDH

int compare(const void *a, const void *b);

int main(int argc, char* argv[], char* env[])
{
	char string[1000];
	char temp[1000];
	
	scanf("%s", string);
	
	int size = strlen(string);
	
	for(int i = 0; i < size; i++)
	{
		strncpy(&temp[i], string+i, size-i);
	}
	
	qsort(temp, sizeof(temp)/sizeof(temp[0]), sizeof(temp[0]), compare);
	
	for(int i = 0; i < size; i++)
	{
		printf("%s\n", &temp[i]);
	}
	
	return 0;
}

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    return strcmp((char *)a, (char *)b);
}