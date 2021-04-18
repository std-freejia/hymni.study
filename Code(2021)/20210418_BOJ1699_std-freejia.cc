#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
// 1699번 제곱수의 합  
 
int D[100001]; 
int n, i, j;

int main(void){
	
	cin >> n;
	 
	for(i = 1; i <= n; i++){
	
		D[i] = i; // i를 1의 제곱의 합으로만 나타내면 항의 개수 i개  
		
		for(j = 1; j*j <= i; j++){
		
			D[i] = min(D[i], D[i- j*j] + 1);
		
		}
	}
 
 	cout << D[n];
 	
	return 0;
}
 