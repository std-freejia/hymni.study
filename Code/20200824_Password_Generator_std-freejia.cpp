#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

// 암호 만들기 (BOJ 1759)

int L, C;
vector<char> alpha;
vector<char> momo{'a', 'e', 'i', 'o', 'u'};

bool check(string &pw){ // 자음 모음 개수 세기 

	int ja = 0, mo = 0;	
	 
	for(char x : pw){
		
		if( find(momo.begin(), momo.end(), x) != momo.end() ){
			mo++;
		}else{
			ja++;
		}
	}
	
	return (ja >= 2 && mo >= 1);

}

void bf(vector<char> &alpha, string st, int idx){

	if(L == st.length()){ // L 개 다 고름  
	
		if(check(st)){ // 자음 모음 개수 충족 여부 확인  
			cout << st << '\n';
		}
		return;
	}
	
	if(alpha.size() <= idx) return;
	
	bf(alpha, st + alpha[idx], idx+1); // idx 위치 문자를 선택 
	
	bf(alpha, st, idx+1);  // 선택 안함  
	
}

int main() {

	freopen("input.txt", "rt", stdin);
	
	string st; // 암호  
	char ch;	
	
	cin >> L >> C; //C개 중에 L개를 골라 암호 만들기  
	
	for(int i = 0; i < C; i++){	
		cin >> ch;
		alpha.push_back(ch);
	}
	
	sort(alpha.begin(), alpha.end());
	bf(alpha, st, 0);
	    
	return 0;
}
