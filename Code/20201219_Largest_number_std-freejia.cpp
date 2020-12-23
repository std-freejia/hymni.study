#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 큰 수 (프로그래머스)

vector<string> v;

bool compare(string a, string b) {// 두 숫자를 붙여봤을 때 큰 경우를 앞으로. 
	return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
	string answer = "";
	int n_size = numbers.size();
	
	for (int i = 0; i < n_size; i++) {
		v.push_back(to_string(numbers[i])); // 문자열로 바꿔서 벡터에 넣기 
	}

	sort(v.begin(), v.end(), compare); // 두 숫자를 붙여봤을 때 큰 경우를 앞으로. 
	
	// 전부 0인경우 처리
	if (v[0] == "0") return "0";

	for (int i = 0; i < n_size; i++) { // 답에 이어붙이기 
		answer += v[i];
	}

	return answer;
}