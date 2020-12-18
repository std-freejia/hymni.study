#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// 문자열 압축

int solution(string s) {
	int answer = s.length();
	int half_len = answer / 2; 

	for (int i = 1; i <= half_len; i++) { // 몇 토막으로 자를지. 
		string temp_answer = ""; // 임시 문자열 
		string temp_str = s.substr(0, i); // 길이 i 토막씩 자른다 
		int temp_cnt = 1; 

		for (int j = i; j < s.length(); j += i) {

			if (temp_str == s.substr(j, i)) temp_cnt++; // 토막과 똑같다면 개수 증가 
			else {
				// temp_cnt를 answer에 붙이고, temp_str도 이어붙인다. 
				if (temp_cnt > 1) temp_answer += to_string(temp_cnt);
				temp_cnt = 1;
				temp_answer += temp_str;
				temp_str = s.substr(j, i);
			}
		}

		// 중복이 있었다면 임시 문자열에 개수와 문자열 이어붙이기. 
		if (temp_cnt > 1) temp_answer += to_string(temp_cnt);
		temp_answer += temp_str;

		if(temp_answer.length() < answer) { // 길이 갱신
			answer = temp_answer.length();
		}

	}


	return answer;
}