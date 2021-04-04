#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;

// 이모티콘 BOJ 14226  

int S; 
bool check[MAX+1][MAX+1];  // 화면의 이모티콘 개수, 클립보드 이모티콘 개수  

int BFS(){

	// 화면의 이모티콘 개수, 클립보드의 이모티콘 개수, 시간  
	queue<pair<pair<int,int>, int> > q;
	
	//이모티콘 1개로 시작  
	q.push({{1, 0}, 0});
	check[1][0] = true;
	 
	int imo=0, clip=0, time=0;
		
	while(!q.empty()){
	
		imo = q.front().first.first;
		clip = q.front().first.second;
		time = q.front().second;
		
		q.pop();
		
		if(imo == S){ // S개 완성  			
			break; 
		}
		
		// 복사  
		if(imo > 0 && imo < MAX){
			if(!check[imo][imo]){
				check[imo][imo] = true;
				q.push({{imo, imo}, time+1});
			}
		}
		
		// 붙여넣기  
		if(clip > 0 && imo+clip <= MAX){
			if(!check[imo+clip][clip]){
				check[imo+clip][clip] = true;
				q.push({{imo+clip, clip}, time+1});
			}  
		}
		
		//삭제
		if(imo-1 >= 0 && !check[imo-1][clip] ){ 
			q.push({{imo-1, clip}, time+1});
		}	 
	} 
	
 	return time; 
}

int main(void){
 
 	cin >> S;
 
	printf("%d", BFS());  // 최소시간 리턴  	 
 
	return 0;
} 