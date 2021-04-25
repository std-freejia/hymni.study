#include <stdio.h>
#include <algorithm>
using namespace std;

int A[1001];
int D[1001];

// 11722번 

int main(void){
 
	int N = 0;
	int i, j, num, max_len = 0;
	
	scanf("%d", &N);
	
	for(i = 1; i <= N; i++){
		scanf("%d", &num);
		A[i] = num;
	}
	// 입력받기 끝
	
	// 뒤에서 시작 
	for(i = N; i >= 1; i--) {
		
		D[i] = 1;
		
		for(j = i+1; j <= N; j++){
				
			if(A[j] < A[i]){
				D[i] = max(D[i], D[j] + 1);
			}
		
		}	
	}
	
	for(i = 1; i <= N; i++){
		
		if(max_len < D[i]){
			max_len = D[i];
		}
	}
	
 	printf("%d", max_len);
 
	return 0;
}

