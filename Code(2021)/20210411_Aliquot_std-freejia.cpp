#include <iostream>
using namespace std;

int N; 
long long answer;

// 약수의합2 BOJ 17427


int main()
{
 	cin >> N;
		
	for (int i = 1; i <= N; i++) {
		
		answer += i * (int)(N / i);
	}

	cout << answer;

	return 0;
}