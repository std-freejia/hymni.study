#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#define endl '\n'
using namespace std;


// 백준 14225 부분수열의 합 

// https://codeforces.com/blog/entry/86796

// freopen("input.txt", "rt", stdin);

int N, i;
int S[21]; // 입력 수열 
bool chk[20000001];
int answer = 1; // 나올 수 없는 가장 작은 자연수 

void check(int num, int sum) {

	chk[sum] = true; // 합이 나온 경우를 체크. 
	if (num == N) return;
	else {
		check(num + 1, sum); // 더하지 않음 
		check(num + 1, sum + S[num]); // 더함 
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
 
	cin >> N; // 수열의 크기 

	for (i = 0; i < N; i++) {
		cin >> S[i];
	}

	// 하나씩 골라본다 
	check(0, 0);

	while (chk[answer] == true) answer++;

	cout << answer;

	return 0;
}