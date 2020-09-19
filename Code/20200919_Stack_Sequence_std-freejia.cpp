#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ���ü���  BOJ 1874 (����)  

int n;
stack<int> st;
vector<char> v; //  +, - ����  
int A[100001];

int main(void){

	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	int v_target = 0; 
	
	for(int i = 1; i <= n; i++){ // 1~n ���� ���� �ִ´�  
	
		st.push(i);
		v.push_back('+'); // ���� �����鼭 '+' �߰�  
		
		// top�� Ÿ���� ���� '-' �߰�  
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
