#include <iostream>
using namespace std;

// 약수의 합2 

int N; 
long long answer;

int main()
{
 	cin >> N;
		
	for (int i = 1; i <= N; i++) {
		
		answer += i * (int)(N / i);
	}

	cout << answer;

	return 0;
}