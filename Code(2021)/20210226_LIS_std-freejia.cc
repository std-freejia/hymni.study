#include <iostream>
#include <algorithm>
using namespace std;


//  가장 긴 증가하는 부분 수열

int A[1001];
int D[1001];

int i, j, len, num, answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	answer = 1;

	cin >> len; // 수열길이 

	for (i = 1; i <= len; i++) {
		cin >> num;
		A[i] = num;
	}

	for (i = 1; i <= len; i++) {
		D[i] = 1; 

		for (j = 0; j < i; j++) { // 자신보다 작은 숫자 세기 

			if (A[i] > A[j]) {
				D[i] = max(D[i], D[j] + 1);
			}
		}

		answer = max(D[i], answer);
	}

	cout << answer;

	return 0;
}