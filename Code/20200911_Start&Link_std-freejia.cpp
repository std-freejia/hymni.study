#include <iostream> 
#include <vector>
#include <algorithm>  // min() 
using namespace std;

int N;
int answer = 2e9;
bool check[22];
int S[22][22]; 

void countPower(){ // 팀별 능력치 비교  

	vector<int> Steam, Lteam; 
	int Spower=0, Lpower=0; 

	for(int i = 0; i < N; i++){  // 1. vector에 팀별 멤버번호 나눠담기 
		if(check[i]) Steam.push_back(i);
		else Lteam.push_back(i);
	}	

	for(int i = 0; i < Steam.size(); i++){ // 2. 팀별 능력치 계산  
 		for(int j = i+1; j < Steam.size(); j++){
 			Spower = Spower + ( S[ Steam[i] ][ Steam[j] ] ) + ( S[ Steam[j] ][ Steam[i] ] );
			Lpower = Lpower + ( S[ Lteam[i] ][ Lteam[j] ] ) + ( S[ Lteam[j] ][ Lteam[i] ] );
		}
	}
	
	// 3. 최소값 갱신 
	answer = min( answer, abs(Spower-Lpower));
	
	return;
}

void divideTeam(int idx, int cnt){ // N명중에 N/2 명 고르기  

	if(cnt == (N/2) ) { // 팀 선택 완료 
		countPower();
		return;
	}
		
	for(int i = idx; i < N; i++){ // DFS로 완전탐색 
	
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
	
	divideTeam(0, 0); // 팀 나누기 
	 
	cout << answer;
	
	return 0;
} 

