#include <iostream> 
using namespace std;
 
// 최대 공약수(gcd)와 최소 공배수(lcm) 를 출력 

int GCD(int a, int b){

	return (b)? GCD(b, a%b) : a;
	
}

int main(void){
 
 	int a, b;  
 	int gcd = 0, lcm = 0;
 	
 	cin >> a >> b; 
  
	gcd = GCD(a, b);
	
	lcm = a*b / gcd;
	
	cout << gcd << '\n' << lcm;
	
	return 0;	
}
