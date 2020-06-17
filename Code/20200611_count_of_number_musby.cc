#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_CNT	3		// 입력 받을 숫자 개수
#define MAX_NUMBER_LEN	3		// 입력 받을 숫자의 길이
#define DIGIT_CNT		10		// 0 ~ 9

bool InputTestCase(int*);
bool ShowDigitCount(int);

int main(int argc, char* argv[])
{
	int mulResult = 1;
	
	// 입력 에러 체크
	if(!InputTestCase(&mulResult)){
		fprintf(stderr, "INPUT TYPE ERROR!");
		exit(EXIT_FAILURE);
	}
	
	if(!ShowDigitCount(mulResult)){
		fprintf(stderr, "TYPE CASTING ERROR!");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

bool InputTestCase(int* mulResult)
{
	int idx = 0;
	int integerNumber = 0;
	char stringNumber[MAX_NUMBER_LEN + 2] = {0,};
	
	while(idx < MAX_NUMBER_CNT){
		// 1.입력 에러 체크 
		// 2.개행문자 및 널문자가 들어갈 공간을 포함(+2)하여 배열 길이 설정
		// 3.scanf로 받을 경우 오버플로우 발생 가능성 존재
		if(NULL == fgets(stringNumber, (MAX_NUMBER_LEN + 2), stdin)){
			return false;
		}
		
		// 문자열로 입력받은 숫자, 정수형 변환 시 에러 체크
		if(EOF == sscanf(stringNumber, "%d", &integerNumber)){
			return false;
		}
		
		(*mulResult) *= integerNumber;
		
		idx++;
	}
	
	return true;
}

bool ShowDigitCount(int mulResult)
{
	int digit[DIGIT_CNT] = {0,};
	char stringNumber[10] = {0,}; // 100 ~ 1,000이므로 자리수가 10개 미만
	int idx = 0;
	int stringNumberLen = 0;
	
	// 곱셈이 끝난 십진수를 문자열로 변환
	if(sprintf(stringNumber, "%d", mulResult) < 0){ 
		return false;
	}
	
	stringNumberLen = strlen(stringNumber);
	printf("%s\n", stringNumber);
	
	while(idx < stringNumberLen){
		// 문자'0'과 숫자0의 차이는 48 = -48 연산을 통해 십진수 도출
		digit[stringNumber[idx] - 48] += 1;
		idx++;
	}
	
	for(idx=0; idx<DIGIT_CNT; idx++){
		printf("%d\n", digit[idx]);
	}
	
	return true;
}