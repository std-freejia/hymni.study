#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    int vsize = numbers.size(); // 정수 배열 크기 

	for (int i = 0; i < vsize-1; i++) {

		for (int j = i + 1; j < vsize; j++) { // 2개를 뽑아서 더한다 
			answer.push_back(numbers[i] + numbers[j]);
		}
	}

	// 정렬 
	sort(answer.begin(), answer.end()); 

	// unique:연속된 중복 원소를 vector의 제일 뒷부분 쓰레기값으로 보냄
	// erase: 쓰레기값 중복 원소들을 삭제 
	
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}