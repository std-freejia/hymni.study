#include <iostream> 
#include <vector>
#include <algorithm>  // min() 
using namespace std;

int N;
int answer = 2e9;
bool check[22];
int S[22][22]; 

void countPower(){ // ���� �ɷ�ġ ��  

	vector<int> Steam, Lteam; 
	int Spower=0, Lpower=0; 

	for(int i = 0; i < N; i++){  // 1. vector�� ���� �����ȣ ������� 
		if(check[i]) Steam.push_back(i);
		else Lteam.push_back(i);
	}	

	for(int i = 0; i < Steam.size(); i++){ // 2. ���� �ɷ�ġ ���  
 		for(int j = i+1; j < Steam.size(); j++){
 			Spower = Spower + ( S[ Steam[i] ][ Steam[j] ] ) + ( S[ Steam[j] ][ Steam[i] ] );
			Lpower = Lpower + ( S[ Lteam[i] ][ Lteam[j] ] ) + ( S[ Lteam[j] ][ Lteam[i] ] );
		}
	}
	
	// 3. �ּҰ� ���� 
	answer = min( answer, abs(Spower-Lpower));
	
	return;
}

void divideTeam(int idx, int cnt){ // N���߿� N/2 �� ����  

	if(cnt == (N/2) ) { // �� ���� �Ϸ� 
		countPower();
		return;
	}
		
	for(int i = idx; i < N; i++){ // DFS�� ����Ž�� 
	
		if(check[i]) continue;

		check[i] = true;
		divideTeam(i+1, cnt+1);
		check[i] = false;
	}
	
}
 

int main(void){
 
 	cin >> N;

 	for(int i = 0; i < N; i++){
 		for(int j = 0; j < N; j++){
 			scanf("%d", &S[i][j]);
		}
	}
	
	divideTeam(0, 0); // �� ������ 
	 
	cout << answer;
	
	return 0;
} 

