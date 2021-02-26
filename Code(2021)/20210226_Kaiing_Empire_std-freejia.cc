#include <iostream>
#include <algorithm>
using namespace std;

// 카잉달력

int T, M, N, x, y;

int gcd(int a, int b){ // 최대공약수

	while(b != 0){
		int t = a % b;
		a = b;
		b = t;
	} 
	
	return a;
} 

int lcm(int a, int b){ // 최소공배수 
	return (a * b) / gcd(a,b);
}

int main(void){

	cin >> T;
	
	while(T--){
	
		cin >> M >> N >> x >> y;
		
		int i = x;
        int endday = lcm(M, N); // 마지막 해 
		int result = -1; // 실패할 경우 답
		
		// i%M == x 이고 i%N == y 를 찾아야 한다. 
		
		for(i = x; i <= endday; i += M){ // x는 M만큼 건너뛴다 
		
            // y == N 인 경우에는, i 가 N으로 나누어 떨어져야 만족 
			if( (y == N && i % N == 0 ) || (i % N == y) ){ 
				result = i; 
				break;
			}
		}
		
		cout << result << '\n';
	}
	 
	return 0;	
}