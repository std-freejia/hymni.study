#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX_NUM 100001
#define DIV_NUM 1234567

// 피보나치 수 (프로그래머스)

int D[MAX_NUM];

int solution(int n) {

	int answer = 0;
	int i = 0;

	D[1] = 1, D[2] = 1;

	for (i = 3; i <= n; i++) {
		D[i] = (D[i - 2] + D[i - 1] ) % DIV_NUM;
	}
	answer = D[n];

	return answer;
}

int main(void) {
	
	cout << solution(3) << endl;
	cout << solution(5) << endl;

	return 0;
} 