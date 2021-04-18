#include <iostream>
#define MODNUM 1000000009
using namespace std;
 
// 15990번  1, 2, 3 더하기 5

long long D[100001][4]; // DP 테이블  
int test_case, n, num; 

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

	D[1][1] = D[2][2] = 1;
	
	D[3][1] = 1;
	D[3][2] = 1;
	D[3][3] = 1;
	
	cin >> test_case;
	
	while(test_case--){
		cin >> num;
        cout << sum_case(num) << '\n';
 	}
	 	
	return 0;
}