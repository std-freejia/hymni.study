#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIN_LEN		100
#define MALLOC(ptr, space)	\
		if(!((ptr) = (char*)malloc(space))){		\
			fprintf(stderr, "Insufficient Memory");	\
			exit(EXIT_FAILURE);						\
		}

int DecimalConverter(char*);
void HammingDistance(int);

int main(int argc, char* argv[])
{
	int testCaseCnt = 0;
	int orDecimal = 0;
	char* oddBinary = NULL;
	char* evenBinary = NULL;
	
	MALLOC(oddBinary, MAX_BIN_LEN);
	MALLOC(evenBinary, MAX_BIN_LEN);
	
	scanf("%d", &testCaseCnt), getchar();
	
	while(testCaseCnt--){
		orDecimal = DecimalConverter(oddBinary) | DecimalConverter(evenBinary);
		HammingDistance(orDecimal);
	}
	
	free(oddBinary), free(evenBinary);
	
	return 0;
}

void HammingDistance(int decimal)
{
	int res = 0;
	
	while(decimal){
		(1 == (decimal & 1)) ?  res++ : res;
		decimal = decimal >> 1;
	}
	
	printf("Hamming distance is %d.\n", res);
}

int DecimalConverter(char* binary)
{
	int idx = 0;
	int decimalNumber = 0;
	fgets(binary, MAX_BIN_LEN, stdin), binary[strlen(binary) - 1] = '\0';
		
	for(idx=0; binary[idx]; idx++){
		decimalNumber = (decimalNumber << 1) + binary[idx] - 48;
	}
	
	return decimalNumber;
}