#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using namespace std;

// �ε�ȣ(BOJ  2529) ����  

 
int k;
char sign[11];  // �ε�ȣ ���� ����   
int num[11]; 	// �������� ������� ����  
bool ch[11];  // ���� �ߺ� ���� 
vector<string> ans; // �ε�ȣ�� �����ϴ� ������ �����ϴ� ���� 
string maxnum, minnum;

bool SignCheck(char a, char b, char oper){ // �ε�ȣ�� ������Ű���� �˻�
	
	if(oper == '<'){
		if(a>b) return false;
		
	} else {// '>'
		if(a<b) return false;
	}
	
	return true;
}

void Combination(int index, string num){ 
	// index : �����ؾ� �� (����������) ���� �ڸ�. 0���� 9���� 10���� ������ ���ؾ� �ϴϱ� index : 0���� 9����. 
	
	if(index == (k+1) ){ // ���� �ϼ�. ���Ϳ� �ִ´� 
		ans.push_back(num); 
		return; 	 
	}
	
	for(int i = 0; i <= 9; i++){
		if(ch[i]) continue; // �̹� ����� ���ڶ�� ������
		
		// ù��° �ڸ� ���ڸ� ���� �Ŷ��, ������ ����. (index == 0)
		//  �װ� �ƴ϶��, ���ڸ� ���� num[index-1] �� ���� �����Ϸ��� ���� i �� �ε�ȣ�� �ѱ��.  
		if(index == 0 || SignCheck(num[index-1], i+'0', sign[index-1])){
			ch[i] = true; // ����
 			Combination(index+1, num + to_string(i)); // ���� �ڸ��� ������ ���� ��� ȣ�� 
			ch[i] = false; // ���� ����  
		}
		
	} 
}
 

int main(void){
 
	cin >> k;
 	
 	for(int i = 0; i < k; i++){
	 	cin >> sign[i];
	}
	
	string st;
	
	Combination(0, "");    

	sort(ans.begin(), ans.end()); // �������� ���� ��, �� �ڰ� �ִ�, �� ���� �ּ�
	
	cout << ans[ans.size()-1] << '\n' << ans[0];

	return 0;
} 

