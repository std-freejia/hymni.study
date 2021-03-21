#include <string>
#include <vector>
using namespace std;

// 이상한 문자 만들기

string answer;
int idx; 

string solution(string s) {

	int s_size = s.size();

	for (int i = 0; i < s_size; i++) {

		char ch = s[i];

		if (s[i] == ' ') { 
			idx = 0;
		}
		else if(1 == idx % 2){ // 홀수 인덱스 -> 소문자
			ch = tolower(s[i]);
			idx++;
		}
		else if (0 == idx % 2) {// 짝수 인덱스 -> 대문자 
			ch = toupper(s[i]);
			idx++;
		}

		answer += ch;
	}

    return answer;
}