#include <iostream>
using namespace std;

// 날짜 계산   (BOJ 1476)

int E, S, M;

int main() {	

	cin >> E >> S >> M; // 15 28 19 
 	int i = 1;
 	
 	while(1){
 		if( ( (i-E)%15 == 0) && ( (i-S)%28 == 0) && ( (i-M)%19 == 0 ) ){		
 			cout << i;
			 break;
		}
		i++;
	}
 
	return 0;
}
