#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 스택수열  BOJ 1874 (지아)  

int n;
stack<int> st;
vector<char> v; //  +, - 저장  
int A[100001];

int main(void){

	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	int v_target = 0; 
	
	for(int i = 1; i <= n; i++){ // 1~n 까지 수를 넣는다  
	
		st.push(i);
		v.push_back('+'); // 숫자 넣으면서 '+' 추가  
		
		// top이 타겟인 순간 '-' 추가  
		while(!st.empty()  && (st.top() == A[v_target]) ){  
			
			st.pop();
			v.push_back('-');
			v_target++;
		} 
	}
	
	if(!st.empty()) cout << "NO";
	else{
		for(int i = 0; i < v.size(); i++){
			printf("%c\n", v[i]);
		}
	}
 	

	return 0;
}
