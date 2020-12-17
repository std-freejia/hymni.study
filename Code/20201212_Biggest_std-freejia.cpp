#include <string>
#include <vector>
using namespace std;
#define endl '\n'

// 큰 수 만들기 

string solution(string number, int k) {
	string answer = "";
	int len = number.length() - k; // 첫 번째 숫자로서 가능한 '최대 인덱스'
	int start_idx = 0; // 비교를 시작할 인덱스 

	for (int i = 0; i < len; i++) { // 첫 번째 숫자로서 가능한 인덱스 
		
		char max_num = number[start_idx]; // 가장 큰 숫자 
		int max_idx = start_idx; // 가장 큰 숫자의 인덱스 

		for (int j = start_idx ; j <= k+i; j++) { // 답이 될 수 있는 길이 만큼만 비교 
			if (max_num < number[j]) {
				max_num = number[j];
				max_idx = j;
			}
		}
		start_idx = max_idx + 1;
		answer += max_num;
	}

	return answer;
}