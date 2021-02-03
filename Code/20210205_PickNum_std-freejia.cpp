#include <iostream>
#include <map>
using namespace std;

// 숫자 골라내기  -- 100점 


int Answer, N, n;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		map<int, int> m;  // <숫자, 숫자의 개수> 
		map<int, int>::iterator it; // 반복자 

		cin >> N; // 숫자 개수 
		
		while (N--) {
			cin >> n;
			it = m.find(n); // map에서 n을 찾은 포인터 반환 

			if (it != m.end()) { // 존재하면, 개수만 증가 
				(*it).second = (*it).second + 1;
			}
			else { // 존재 안하면, 숫자 n이 1개라고 입력 
				m.insert({ n, 1});
			}
		}

		for (it = m.begin(); it != m.end(); it++) {
			if ((*it).second % 2 == 1) { // 홀수 개인 것만 XOR 연산 
 				Answer ^= (*it).first;
			}
		}
		cout << "Case #" << test_case + 1 << '\n';
		cout << Answer << '\n';
		m.clear(); // map의 원소들 전부 삭제 
	}

	return 0;
}