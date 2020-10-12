#include <iostream> 
using namespace std;
 
// �ִ� �����(gcd)�� �ּ� �����(lcm) �� ��� 

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
