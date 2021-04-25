#include <stdio.h>
#include <algorithm>
using namespace std;
 
int A[1001][4];  // 3색 값 입력 받음  
int D[1001][4];
 
// 1149번
 
int main(void){
 
 	int house, fir, se, th = 0;
 	int i = 0;
 	int res_min = 0;
 	
	scanf("%d", &house); 	
 
 	for(i = 1; i <= house; i++){
 		scanf("%d %d %d", &fir, &se, &th); 
 		A[i][1] = fir;
 		A[i][2] = se;
 		A[i][3] = th;
	}
   	 // 입력받기 끝
	 
   	D[1][1] = A[1][1];
	D[1][2] = A[1][2];
	D[1][3] = A[1][3];
   	
	// 1칸을 채울 때, 1칸과 직전줄의 2또는 3 
  	for(i = 2; i <= house; i++){

 		D[i][1] = min(D[i-1][2], D[i-1][3]) + A[i][1]; 
 		D[i][2] = min(D[i-1][1], D[i-1][3]) + A[i][2]; 
 		D[i][3] = min(D[i-1][1], D[i-1][2]) + A[i][3];  
	}
	
	printf("%d", min( min(D[house][1], D[house][2]), D[house][3] ));
 	
	return 0;
}