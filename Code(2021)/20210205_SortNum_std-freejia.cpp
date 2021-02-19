#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 정수 정렬하기(10000)  -- 100점 

long long Answer;
int N;
vector<int> v;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
	
		cin >> N; // 숫자 개수 
		int n = 0;

		for (int i = 0; i < N; i++) { // 숫자들 입력받기 
			cin >> n;
			v.push_back(n);
		}

		// 정렬 
		sort(v.begin(), v.end()); 

		for (int i = 0; i < N; i++) { // 짝수 인덱스 +연산 , 홀수 인덱스 - 연산 
			if (i % 2 == 0) {
				Answer += v[i];
			}
			else {
				Answer -= v[i];
			}
		}

		cout << "Case #" << test_case + 1 << '\n';
		cout << Answer << '\n';

		v.clear(); // 벡터 원소들 삭제 
	}

	return 0;
}
