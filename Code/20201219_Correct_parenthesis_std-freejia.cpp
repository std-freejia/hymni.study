#include <string>
#include <iostream>
#include <stack>
using namespace std;

// 올바른 괄호 

bool solution(string s)
{
	bool answer = true;
	int len = s.length();
	stack<char> st;

	for (int i = 0; i < len; i++) {

		if ('(' == s[i]) { // 여는 괄호
			st.push('(');
		}
		else { // 닫는 괄호 
			if (st.empty()) st.push(')');
			else {
				if ('(' == st.top()) {
					st.pop();
				}
				else {
					st.push(')');
				}
			}
			
		}
	}

	if (!st.empty()) answer = false;
	
	return answer;
}