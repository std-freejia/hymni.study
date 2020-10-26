#include <iostream>
#include <algorithm> 
using namespace std;


int N; 
int A[10001];
int D[10001];
 
void process_stdin() { // 입력받기  

	//freopen("input.txt", "rt", stdin);

	cin >> N;
	
	for(int i = 1; i <= N; i++){
		scanf("%d", &A[i]);
	}
}

int main() {	

	process_stdin();
	
	D[1] = A[1];
	D[2] = A[1] + A[2];
 	
	for(int i = 3; i <= N; i++){
		D[i] = max(A[i] + A[i-1] + D[i-3], A[i] + D[i-2]); // OOXO, OXO
		D[i] = max(D[i], D[i-1]);  // 마지막 잔을 안마신 경우.   // XO
	}

    cout << D[N];
 
	return 0;
}
