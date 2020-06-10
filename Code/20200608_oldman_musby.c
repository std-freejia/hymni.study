#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_LEN	32

int timer[] = {
	3, 3, 3,
	4, 4, 4, 
	5, 5, 5,
	6, 6, 6,
	7, 7, 7, 
	8, 8, 8, 8,
	9, 9, 9,
	10, 10, 10, 10
};

int main(int argc, char* argv[])
{
	char* phone = (char*)malloc(MAX_PHONE_LEN);
	int latency = 0;
	int idx = 0;
	
	fgets(phone, MAX_PHONE_LEN, stdin);
	phone[strlen(phone) - 1] = '\0';

	while('\0' != phone[idx]){
		latency += timer[phone[idx] - 'A'];
		idx++;
	}
	
	printf("result : %d\n", latency);
	
	free(phone);
	
	return 0;
}