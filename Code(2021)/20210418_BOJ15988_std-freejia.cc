#include <iostream>
#define MODNUM 1000000009
using namespace std;

// 15988번   1, 2, 3 더하기 3  

long long arr[1000000]; // DP 테이블
int tc, num;

int sum_case(int num){
		
	int i = 0;
	
	for(i = 4; i <= num; i++){
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
		arr[i] %= MODNUM;
	}
	
	return arr[num];
}
  
int main(void){
 	 
 	cin >> tc;
 
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	while(tc--){
		cin >> num;
        cout << sum_case(num) << '\n';
 	}
	
	return 0;
}