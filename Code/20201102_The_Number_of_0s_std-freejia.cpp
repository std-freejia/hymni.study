#include <iostream>
#include <algorithm> 
using namespace std;

// ���� 0�� ����  (BOJ 2004) ����  

int n, m;
int five, two; // 5�� ����, 2�� ����  

int five_cnt(int n) {
	
	int cnt = 0;
	
	for(long long i = 5; i <= n; i*=5){
		cnt += (n/i);
	}
	
	return cnt;
}


int two_cnt(int n) {
	
	int cnt = 0;
	
	for(long long i = 2; i <= n; i*=2){
		cnt += (n/i);
	}
	
	return cnt;
}

int main() {	
 
 	cin >> n >> m;
 	
 	int five = five_cnt(n) - five_cnt(m) - five_cnt(n-m);
 	int two = two_cnt(n) - two_cnt(m) - two_cnt(n-m);
 	
 	cout << min(five, two);
 	
	return 0;
} 
