#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN		1000
#define MALLOC(ptr, space)	\
		if(!((ptr) = (char*)malloc(space))){		\
			fprintf(stderr, "Insufficient Memory");	\
			exit(EXIT_FAILURE);						\
		}
		
#define MOD(X)			(X) % 2

#define CHK_UPPER(X)	'A' <= (X) && (X) <= 'Z'
#define CHK_LOWER(X)	'a' <= (X) && (X) <= 'z'

#define DO_UPPER(X)		(X) -= 32
#define DO_LOWER(X)		(X) += 32

void StrangeString(char*);

int main(int argc, char* argv[])
{
	char* msg = NULL;
	MALLOC(msg, MAX_STR_LEN);
	
	fgets(msg, MAX_STR_LEN, stdin);
	
	StrangeString(msg);
	
	printf("%s\n", msg);
	
	free(msg);
	
	return 0;
}

void StrangeString(char* msg)
{
	int idx = 0;

	while('\n' != msg[idx]){
		
		if(' ' == msg[idx]){
			idx++;
			continue;
		}
		
		if(0 == MOD(idx)){
			(true == CHK_LOWER(msg[idx])) ? DO_UPPER(msg[idx]) : false;
		}else{
			(true == CHK_UPPER(msg[idx])) ? DO_LOWER(msg[idx]) : false;
		}
		
		idx++;
	}
	
}