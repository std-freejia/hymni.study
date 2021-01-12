#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 영어 끝말잇기 

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	answer.resize(2, 0); // {0, 0} 으로 초기화 
	int words_vsize = words.size(); // 확인할 단어들 개수 

	vector<string> records; // 등장한 단어들 저장할 벡터 
	records.push_back(words[0]); // 첫 번째 단어 벡터에 저장 

	char last_ch = words[0].back(); // 첫 번째 단어의 마지막 글자 저장 
	int i = 1;
	
	for (i = 1; i < words_vsize; i++) {	// 모든 단어들 확인 	

		if (words[i].front() == last_ch) { // 끝글자와 앞글자 맞는지 확인 
			// 이미 사용된 단어인지 확인 
			if (records.end() == find(records.begin(), records.end(), words[i]) ) {
				
				last_ch = words[i].back(); // 마지막 글자 갱신 
				records.push_back(words[i]); // 사용한 단어는 records 에 저장 
				continue; // 다음 단어 확인 
			}
		}

		answer[0] = (i % n) + 1; // 자신의 차례 
		answer[1] = (i / n) + 1; // 탈락자 번호
		break;

	}

	return answer;
}