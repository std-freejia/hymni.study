#include <iostream> 
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 후위표기식2  PostfixNotation2  (지아) 

int N;
char C[101];
vector<double> v;
stack<double> st;

int main(void){
   	
	cin >> N;
 
 	scanf("%s", &C);
 	
 	while(N--){ // 알파벳 N개 입력받기  (A부터 순서대로 N개 입력받는다) 
 		int num = 0;
 		cin >> num;
 		v.push_back(num);
	} // 입력받기 끝 
	
	
	// 문자열 C 순회
	for(int i = 0; C[i] != NULL; i++){   
		
		if(C[i] >= 'A' && C[i] <= 'Z'){ // 숫자면, push
		
			// C[i]에서 'A' ASCII 65를 뺀다. v의 인덱스 나옴. -> 앒파벳에 대응하는 num  
			st.push( v[C[i]-65] ); 
			
		}else{
			// 연산자 만나면, 숫자 2개 pop 해서 연산   
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

 			st.push(ans); // 연산 결과를 푸시  
		}
	} 
 
 	printf("%.2f\n", st.top()); 

	return 0;	
}
