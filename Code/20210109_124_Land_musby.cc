#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN		1000
#define MALLOC(ptr, space)	\
		if(!((ptr) = (char*)malloc(space))){		\
			fprintf(stderr, "Insufficient Memory");	\
			exit(EXIT_FAILURE);						\
		}
#define CHK_ZERO(X)			0 == (X) % 3

#define DO_NOT_CARRY(X)		(X) / 3 - 1
#define DO_DIV(X)			(X) / 3

void Ternary(int);

int main(int argc, char* argv[])
{
	int input = 0;
	
	scanf("%d", &input);
	
	Ternary(input);
	
	return 0;
}

void Ternary(int decimalNumber)
{
	char* temp = NULL;
	int idx = 0;
	
	MALLOC(temp, MAX_STR_LEN);
	
	while(0 != decimalNumber){
		
		if(CHK_ZERO(decimalNumber)){
			temp[idx] = 4;
			decimalNumber = DO_NOT_CARRY(decimalNumber);
		}else{
			temp[idx] = decimalNumber % 3;
			decimalNumber = DO_DIV(decimalNumber);	
		}

		idx++;
		
	}
	
	while(0 <= --idx){
		printf("%d", temp[idx]);
	}
	
	free(temp);
	
}



