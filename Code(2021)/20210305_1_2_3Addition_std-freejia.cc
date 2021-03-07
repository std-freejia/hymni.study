#include <iostream>
#define endl '\n'
using namespace std;

// 1,2,3만들기 

int T, N, i; //테스트 케이스, 정수, 반복문 변수 
int D[12];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	cin >> T;

	while (T--) {

		cin >> N;

		for (i = 4; i <= N; i++) {
			D[i] = D[i - 1] + D[i - 2] + D[i - 3];
		}

		cout << D[N] << endl;
	}

	
	return 0;
}