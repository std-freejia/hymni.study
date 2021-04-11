#include <bits/stdc++.h>
using namespace std;


// 연속합 (BOJ 1912)

int A[100002];
int D[100002];

int len, num, i;
long long max_value;


int main(){

	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);
	
	cin >> len; // 수열길이 
	 
	for(i = 1; i <= len; i++){
		cin >> A[i];
	}
	
	max_value = D[1] = A[1];
	
	for(i = 2; i <= len; i++){
	
		D[i] = max(D[i-1] + A[i], A[i]);
		
		if(max_value < D[i]) max_value = D[i];
	}
	
	cout << max_value;

	return 0;
}
