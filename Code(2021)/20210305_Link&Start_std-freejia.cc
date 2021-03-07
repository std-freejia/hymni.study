#include "bits/stdc++.h"
#define endl '\n'
using namespace std;


int N; // 사람 수 
int M[21][21];
int check[21];
int min_diff = 2e9;

int Sum(vector<int> v) { // 벡터에 있는 인덱스들로만 조합한 능력치 

	int sum_num = 0;

	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			sum_num =  sum_num + (M[v[i]][v[j]] + M[v[j]][v[i]]);
		}
	}

	return sum_num;
}

void Synergy() {
	vector<int> start, link; // 팀에 속한 사람들의 번호를 저장 

	for (int i = 0; i < N; i++) {
		if (check[i]) {
			start.push_back(i);
		}
		else {
			link.push_back(i);
		}
	}

	min_diff = min(min_diff, abs(Sum(start) - Sum(link)));
}

void Define_Team(int idx, int cnt, int end_num) { // DFS 조합으로 팀 나누기 

	if (cnt == end_num) {
		Synergy();
		return;
	}

	for (int i = idx; i < N; i++) { // idx번째 번호 사람을 선택 할지 말지.
		if (check[i]) continue;

		check[i] = 1; // 선택
		Define_Team(i+1, cnt + 1, end_num);
		check[i] = 0; // 선택 안함 
	}
}

int main()
{
	cin >> N; 

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &M[i][j]); // 입력받기 끝 
		
	
	// 팀 나누기 
	for (int i = 2; i <= N-2; i++) { // 2명 고르기. 3명 고르기. .. N-2명 고르기
		Define_Team(0, 0, i);
	}
	
	cout << min_diff;

	return 0;
}