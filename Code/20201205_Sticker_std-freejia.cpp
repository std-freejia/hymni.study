#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 100001
#pragma warning(disable:4996)


int T, max_len; // 테스트 케이스, 최대 길이 
int INPUT[3][MAX_NUM];;
int D[3][MAX_NUM];

int Cal() {

	D[1][1] = INPUT[1][1];
	D[2][1] = INPUT[2][1];

	D[1][2] = D[2][1] + INPUT[1][2]; // 대각선이랑 더했을 떄.
	D[2][2] = D[1][1] + INPUT[2][2];

	for (int i = 3; i <= max_len; i++) {
		D[1][i] = INPUT[1][i] + max(D[2][i - 1], D[2][i - 2]);
		D[2][i] = INPUT[2][i] + max(D[1][i - 1], D[1][i - 2]);
	}

	return max(D[1][max_len], D[2][max_len]);
}

int main() {
 
	cin >> T;
	
	while (T--) {
		cin >> max_len;


		for (int i = 1; i <= max_len; i++) {
			cin >> INPUT[1][i] ;
		}

		for (int i = 1; i <= max_len; i++) {
			cin >> INPUT[2][i];
		}

		cout << Cal() << '\n';
	}

	return 0;
}
