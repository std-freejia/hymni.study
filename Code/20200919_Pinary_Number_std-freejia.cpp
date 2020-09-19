#include <iostream>
#include <algorithm>
using namespace std;

// 이친수  BOJ 2193 지아  

long long D[91][2];
int N;

int main(){
	
	cin >> N;
	
	D[1][0] = 0;
	D[1][1] = 1;
	
	D[2][0] = 1;
	D[2][1] = 0;
	
	D[3][0] = 1;
	D[3][1] = 1;
		
	for(int i = 4; i <= N; i++){
		D[i][0] = D[i-1][0] + D[i-2][0];
		D[i][1] = D[i-1][1] + D[i-2][1];
	}
	
	cout << D[N][0] + D[N][1];
	
	return 0;
}
