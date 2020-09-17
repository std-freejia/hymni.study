#include <iostream> 
#include <stack>
using namespace std;

// 에디터 BOJ 1406 (지아) 
/*
L : L이 비지않았으면 , L에서 하나 꺼내서 R로 넣기 
D : R이 비지않았으면 , R에서 하나 꺼내서 L로 넣기 
B : L이 비지 않았으면, L의 탑을 삭제. 
P $ : L에 $를 푸시 
*/ 	

  
stack<char> Lst, Rst;
int order_num;
char order, ch;

int main(void){
 
 	string input;
 	cin >> input >> order_num;
 
	// 1. 모든 문자를 Lst 에 넣는다 (==커서가 문장 맨 뒤) 
	for(int i = 0; i < input.size(); i++){
		Lst.push(input[i]);
	}

	while(order_num--){ // 2. 명령어 수행  
		
		cin >> order;
		
		if('L' == order){
		
			if(!Lst.empty()) {
				ch = Lst.top();
				Lst.pop();
				Rst.push(ch);
			}
		}else if('D' == order) {
		
			if(!Rst.empty()) {
				ch = Rst.top();
				Rst.pop();
				Lst.push(ch);
			}
		}else if('B'== order){
			
			if(!Lst.empty()) {
				Lst.pop();
			}
		}else if('P' == order){
			cin >> ch;
			Lst.push(ch);
		}
	} 
  
 	// 3. Lst에서 모두 꺼내서 Rst으로 옮긴다 
	while(!Lst.empty()){
		ch = Lst.top();
		Rst.push(ch);
		Lst.pop();
	}
	
	// 4. Rst를 전부 출력한다.  
	while(!Rst.empty()){
		cout << Rst.top();
		Rst.pop();
	}
	
	return 0;
} 
