#include <string>
#include <vector>
using namespace std;


int gcd(int a, int b) { // 최대공약수 
	
	int temp = 0; 
	
	if( a < b ) swap(a, b); // a에 큰 숫자를 놓는다. 
	
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int lcm(int a, int b) { // 최소공배수
	return a * b / gcd(a, b);
}

int solution(vector<int> v) {
    
    int answer = v[0];
    int vsize = v.size();

	for (int i = 1; i < vsize; i++) {
		answer = lcm(answer, v[i]);
	}
    
    return answer;
}