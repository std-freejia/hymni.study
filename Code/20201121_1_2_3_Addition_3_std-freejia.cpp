#include <iostream> 

#define LIMIT 1000001
#define DIV 1000000009
using namespace std;
 
int TC, N;
long long D[LIMIT];

int DP(){

	D[1] = 1;
	D[2] = D[1] + 1;
	D[3] = D[1] + D[2] + 1;
 	
	for(int i = 4; i <= N; i++){
		D[i] = D[i-3] + D[i-2] + D[i-1];
		D[i] %= DIV;
	}
	
	return D[N];
}

int main() {	
 
	cin >> TC;
	
	while(TC--){
	
		cin >> N;
		int cnt = DP();
		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
} 
