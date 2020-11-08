#include <iostream> 
#include <queue>
#include <algorithm>
#include <utility>  // pair 

using namespace std;

// 이모티콘 (BOJ 14226)  

int S; // 화면에 있는 이모티콘 목표 개수  
int time[2001][2001]; //  screen, clip 개수에 따른 시간 저장   

int BFS(){

	queue<pair<int,int> > q;
	
	q.push({1, 0}); // {화면 개수 , 클립보드 개수} 
	time[1][0] = 0; // 처음에 화면1개 클립보드0개 에는 0초   
	
	int screen=0, clip=0;
	
	while(!q.empty()){
	
		screen = q.front().first;
		clip = q.front().second;
		 
		q.pop();
		
		if(screen == S) { // S개 완성  
			break;
		}
		
		// 복사, 삭제, 붙여넣기  
		int nextScreen[4] = {screen, screen-1, screen+clip};
		int nextClip[4] = {screen, clip, clip};
		
		for(int i = 0; i < 3; i++){
			
			if(nextScreen[i] < 0 || nextScreen[i] > S*2 ) continue; // 인덱스 
			if(time[ nextScreen[i] ][ nextClip[i] ] != 0) continue; // 이미 방문  

			q.push({nextScreen[i], nextClip[i]});
			time[nextScreen[i]][nextClip[i]] = time[screen][clip] + 1; 
		}
	 
	}
	
	return time[screen][clip];
}

void input(){

	cin >> S;  
}

int main() {	

 	input();
	cout << BFS();

	return 0;
} 
