#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN		150000
#define MALLOC(ptr, space)	\
		if(!((ptr) = (char*)malloc(space))){		\
			fprintf(stderr, "Insufficient Memory");	\
			exit(EXIT_FAILURE);						\
		}

#define CHK_ZERO(X)		'0' == (X)

void BinaryMaker();

int main(int argc, char* argv[])
{
	BinaryMaker();
	
	return 0;
}

void BinaryMaker()
{
	char* binaryString = NULL;
	int falseCnt = 0, trueCnt = 0;
	int idx = 0;
	int temp = 0;
	int loopCnt = 1;
	
	MALLOC(binaryString, MAX_STR_LEN);
	
	fgets(binaryString, MAX_STR_LEN, stdin), binaryString[strlen(binaryString) - 1] = 0;
	
	for(;idx < strlen(binaryString); idx++){
		CHK_ZERO(binaryString[idx]) ? falseCnt++ : trueCnt++;
	}
	
	while(1 != trueCnt){

		if(0 == trueCnt & 1){
			falseCnt++;
		}else{
			temp++;
			trueCnt = trueCnt >> 1;
		}
		
		if(0 == trueCnt){
			trueCnt = temp;
			temp = 0;
			loopCnt++;
		}
		
	}
	
}
