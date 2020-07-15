#include <string>
#include <vector>
#include <stack>
using namespace std;

// 쇠막대기 프로그래머스 (std-freejia) 

int solution(string arrangement) {

    int answer = 0;
	int i, len = 0;
	stack<char> st;
	bool open_flag = true; // 직전 괄호가 여는괄호였다면 true 
	 
	len = arrangement.size();
	
	for(i=0; i<len; i++){
		
		char pa = arrangement[i];
		
		if(pa == '(') { // 여는 괄호라면  
			st.push(pa);
			open_flag = true;
			
		}else{ // ')' 닫는 괄호라면  
		    st.pop();
			if(open_flag){ // 레이저: 여는괄호 닫는괄호 연속이므로. 
				answer += st.size();
			}else{
				answer++;
			}
			open_flag = false;
			
			
		}
	}
	

    return answer;
}
