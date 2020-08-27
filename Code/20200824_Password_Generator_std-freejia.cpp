#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

// ��ȣ ����� (BOJ 1759)

int L, C;
vector<char> alpha;
vector<char> momo{'a', 'e', 'i', 'o', 'u'};

bool check(string &pw){ // ���� ���� ���� ���� 

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

	if(L == st.length()){ // L �� �� ��  
	
		if(check(st)){ // ���� ���� ���� ���� ���� Ȯ��  
			cout << st << '\n';
		}
		return;
	}
	
	if(alpha.size() <= idx) return;
	
	bf(alpha, st + alpha[idx], idx+1); // idx ��ġ ���ڸ� ���� 
	
	bf(alpha, st, idx+1);  // ���� ����  
	
}

int main() {

	freopen("input.txt", "rt", stdin);
	
	string st; // ��ȣ  
	char ch;	
	
	cin >> L >> C; //C�� �߿� L���� ��� ��ȣ �����  
	
	for(int i = 0; i < C; i++){	
		cin >> ch;
		alpha.push_back(ch);
	}
	
	sort(alpha.begin(), alpha.end());
	bf(alpha, st, 0);
	    
	return 0;
}
