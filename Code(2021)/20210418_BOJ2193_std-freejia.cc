#include <iostream>
using namespace std;
 
 // 2193번 이친수 

long long arr[91][2]; // DP테이블 
int n, i;

int main(void){

	cin >> n;

	arr[1][1] = arr[2][0] = arr[3][0] = arr[3][1] = 1;
	
	for(i = 4; i <= n; i++){
		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][0];
	}
	
    cout << arr[n][0] + arr[n][1];
 	
	return 0;
}