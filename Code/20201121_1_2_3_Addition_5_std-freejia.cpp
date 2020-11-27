#include <stdio.h>
#define MODNUM 1000000009
using namespace std;
 
// 1, 2, 3 ¥ı«œ±‚ 5  (BOJ 15990)


long long D[100001][4]; 

long long sum_case(int num){

	int i = 0;
	
	for(i=4; i <= num; i++){
		D[i][1] = (D[i-1] [2] + D[i-1] [3]) % MODNUM;
		D[i][2] = (D[i-2] [1] + D[i-2] [3]) % MODNUM;
		D[i][3] = (D[i-3] [1] + D[i-3] [2]) % MODNUM;
	}
	
	return (D[num][1] + D[num][2] + D[num][3])  % MODNUM;
	
}

int main(void){

	int test_case, n = 0, num = 0;
	
	D[1][1] = D[2][2] = 1;
	
	D[3][1] = 1;
	D[3][2] = 1;
	D[3][3] = 1;
	
	scanf("%d", &test_case);
	
	while(test_case--){
		scanf("%d", &num);
		printf("%lld\n", sum_case(num));
	}
	 	
	return 0;
}
