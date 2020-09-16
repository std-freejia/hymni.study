#include <iostream> 
#include <vector>
using namespace std;
 
// 알파벳 찾기 10809번 지아  
 
string S;

vector<int> alpha(27, -1); // 없는 문자는 전부 -1로 초기화  

int main(void){
 
 	freopen("input.txt", "rt", stdin);
 
	cin >> S;
	
	for(int i=0; i<S.size(); i++){  // '처음'나온 위치를 저장하는 것이니까 -1이 아닐 때만 위치를 저장  
		if(alpha[S[i]-'a'] == -1){
			alpha[S[i]-'a'] = i;
		}
	}
	
	for(int i = 0; i < 26; i++){
		cout << alpha[i] <<' ';
	}

	return 0;
} 
