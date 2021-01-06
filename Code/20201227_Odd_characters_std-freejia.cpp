#include <string>
#include <vector>
using namespace std;

string solution(string s) {

	string answer="";
	int idx=0; // 단어 안에서의 인덱스 
	int s_size = s.size();

	for (int i = 0; i < s_size; i++) { // 문자열 s의 인덱스 

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