#include <iostream> 
#include <vector>
using namespace std;
 
// ���ĺ� ã�� 10809�� ����  
 
string S;

vector<int> alpha(27, -1); // ���� ���ڴ� ���� -1�� �ʱ�ȭ  

int main(void){
 
 	freopen("input.txt", "rt", stdin);
 
	cin >> S;
	
	for(int i=0; i<S.size(); i++){  // 'ó��'���� ��ġ�� �����ϴ� ���̴ϱ� -1�� �ƴ� ���� ��ġ�� ����  
		if(alpha[S[i]-'a'] == -1){
			alpha[S[i]-'a'] = i;
		}
	}
	
	for(int i = 0; i < 26; i++){
		cout << alpha[i] <<' ';
	}

	return 0;
} 
