#include <iostream> 
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// ����ǥ���2  PostfixNotation2  (����) 

int N;
char C[101];
vector<double> v;
stack<double> st;

int main(void){
   	
	cin >> N;
 
 	scanf("%s", &C);
 	
 	while(N--){ // ���ĺ� N�� �Է¹ޱ�  (A���� ������� N�� �Է¹޴´�) 
 		int num = 0;
 		cin >> num;
 		v.push_back(num);
	} // �Է¹ޱ� �� 
	
	
	// ���ڿ� C ��ȸ
	for(int i = 0; C[i] != NULL; i++){   
		
		if(C[i] >= 'A' && C[i] <= 'Z'){ // ���ڸ�, push
		
			// C[i]���� 'A' ASCII 65�� ����. v�� �ε��� ����. -> ���ĺ��� �����ϴ� num  
			st.push( v[C[i]-65] ); 
			
		}else{
			// ������ ������, ���� 2�� pop �ؼ� ����   
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			double ans = 0.0;
 
			if(C[i] == '*'){
				ans = a*b;
			}else if(C[i] == '/'){
				ans = a/b;
			}else if(C[i] == '+'){
				ans = a+b;
			}else if(C[i] == '-'){
				ans = a-b;
			}

 			st.push(ans); // ���� ����� Ǫ��  
		}
	} 
 
 	printf("%.2f\n", st.top()); 

	return 0;	
}
