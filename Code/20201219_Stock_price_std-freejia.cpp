#include <stack>
#include <vector>
using namespace std;

// 주식가격 

vector<int> solution(vector<int> prices) {
	int size = prices.size();
	vector<int> answer(size);
	stack<int> st;
    
    for(int i = 0; i < size; i++){
    	
    	// 스택이 비어있지 않고, 스택 top 값이 현재값보다 크다면, 
		while(!st.empty() && prices[st.top()] > prices[i]){
			answer[st.top()] = i-st.top();
			st.pop(); 
		}
		st.push(i);
	}
	
	while(!st.empty()){
		answer[st.top()] = size-st.top()-1;
		st.pop();
	}
    
    return answer;
}