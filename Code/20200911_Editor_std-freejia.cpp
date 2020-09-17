#include <iostream> 
#include <stack>
using namespace std;

// ������ BOJ 1406 (����) 
/*
L : L�� �����ʾ����� , L���� �ϳ� ������ R�� �ֱ� 
D : R�� �����ʾ����� , R���� �ϳ� ������ L�� �ֱ� 
B : L�� ���� �ʾ�����, L�� ž�� ����. 
P $ : L�� $�� Ǫ�� 
*/ 	

  
stack<char> Lst, Rst;
int order_num;
char order, ch;

int main(void){
 
 	string input;
 	cin >> input >> order_num;
 
	// 1. ��� ���ڸ� Lst �� �ִ´� (==Ŀ���� ���� �� ��) 
	for(int i = 0; i < input.size(); i++){
		Lst.push(input[i]);
	}

	while(order_num--){ // 2. ��ɾ� ����  
		
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
  
 	// 3. Lst���� ��� ������ Rst���� �ű�� 
	while(!Lst.empty()){
		ch = Lst.top();
		Rst.push(ch);
		Lst.pop();
	}
	
	// 4. Rst�� ���� ����Ѵ�.  
	while(!Rst.empty()){
		cout << Rst.top();
		Rst.pop();
	}
	
	return 0;
} 
