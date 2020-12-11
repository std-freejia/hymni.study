#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
#define MODNUM 1000000000 


int arr[101][11];
int main(void){

	int n = 0, i = 0, j = 0;
	long long sum = 0;
	
	scanf("%d", &n);
	
	for(i=1; i<=9; i++){  
		arr[1][i] = 1;
	}
	
	for(i = 2; i <= n; i++){ //  n : 몇 자리 수 인지  
			
		for(j=0; j <= 9; j++){ //  숫자의 마지막 자리 수  
		
			if(j == 0) 
				arr[i][j] = arr[i-1][j+1] % MODNUM;
			else if(j == 9) 
				arr[i][j] = arr[i-1][j-1] % MODNUM;
			else 
				arr[i][j] = ( arr[i-1][j-1] + arr[i-1][j+1] ) % MODNUM;
		}
	}
	
	
	for(i = 0; i <= 9; i++){  
		sum += arr[n][i] ;
	}
	
	printf("%lld", sum % MODNUM);
	
	return 0;
}