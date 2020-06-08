#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int i = 0, sum = 0, str_length = 0;
	char* alpha = (char*)malloc(sizeof(char) * 20);
	
	freopen("input.txt", "rt", stdin);

	scanf("%s", alpha);

	str_length = strlen(alpha);

	for (i = 0; i < str_length; i++) {

		if ('A' <= alpha[i] && alpha[i] <= 'C') {
			sum += 3;
		}else if ('D' <= alpha[i] && alpha[i] <= 'F') {
			sum += 4;
		}else if ('G' <= alpha[i] && alpha[i] <= 'I') {
			sum += 5;
		}else if ('J' <= alpha[i] && alpha[i] <= 'L') {
			sum += 6;
		}else if ('M' <= alpha[i] && alpha[i] <= 'O') {
			sum += 7;
		}else if ('P' <= alpha[i] && alpha[i] <= 'S') {
			sum += 8;
		}else if ('T' <= alpha[i] && alpha[i] <= 'V') {
			sum += 9;
		}else if ('W' <= alpha[i] && alpha[i] <= 'Z') {
			sum += 10;
		}
	}

	printf("%d", sum);
	
	free(alpha);

	return 0;
}
