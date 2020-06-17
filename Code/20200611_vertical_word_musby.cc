#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW		5
#define MAX_COL		15

bool InputTestCase(int*);
void ShowVerticalWord(int);

char words[MAX_ROW][MAX_COL] = {0,};

int main(int argc, char* argv[])
{
	int longestWordLen = 0;
	
	// 입력 에러 체크
	if(!InputTestCase(&longestWordLen)){
		fprintf(stderr, "INPUT TYPE ERROR!");
		exit(EXIT_FAILURE);
	}
	
	// 세로 출력
	ShowVerticalWord(longestWordLen);
	
	return 0;
}

bool InputTestCase(int* longestWordLen)
{
	int idx = 0;
	int wordLen = 0;
	
	while(idx < MAX_ROW){
		// 표준 입력 에러 체크
		if(NULL == fgets(words[idx], MAX_COL, stdin)){
			return false;
		}
		
		// 표준 입력 시 포함되는 개행문자 제거
		wordLen = strlen(words[idx]) - 1;
		words[idx][wordLen] = 0;
		
		// 가장 긴 단어의 길이 = 반복 횟수 제한
		if(*longestWordLen < wordLen){
			*longestWordLen = wordLen;
		}
		
		idx++;
	}
	
	return true;
}

void ShowVerticalWord(int longestWordLen)
{
	int col = 0, row = 0;
	
	// 열 인덱스를 고정하고 행 인덱스 변경하며 출력
	while(col < longestWordLen){
		
		char ch = words[row][col];
		
		// words의 사용되지 않은 영역은 0으로 초기화 되므로 ch와 비교
		if(0 != ch){
			printf("%c", ch);
		}
		
		// 삼항연산자를 통해 반복 횟수 감소
		(MAX_ROW == (row + 1)) ? row = 0, col++ : row++;
	}
}