#include <bits/stdc++.h>
using namespace std;

// 1로만 되어있는 수 중에서. 
// 2의 배수, 5의 배수가 아닌 n 이 주어진다. 
 
// 1로만 이루어진 n의 배수 찾기 

int n;

int main(){

	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);

	freopen("input.txt", "rt", stdin);
	
	while(cin >> n){
		// 1로 이루어진 n의 배수 중, 가장 작은 수의 자리수
		int answer = 1; 
		
		// k : 찾고자 하는 1로만 이루어진 n의 배수  
		long long k = 1; 
		
		while(1){
			//  n의 배수  
			if(k % n == 0){
				cout << answer << '\n';
				break;
			}
			// 배수가 아니라면, 1을 덧붙인다 
			k %= n;
			k = (k*10) +1;
			answer += 1;
		}
	}
	
	return 0;
}
