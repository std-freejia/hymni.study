#include <iostream> 
#include <queue>
#include <algorithm>
#include <utility>  // pair 

using namespace std;

// �̸�Ƽ�� (BOJ 14226)  

int S; // ȭ�鿡 �ִ� �̸�Ƽ�� ��ǥ ����  
int time[2001][2001]; //  screen, clip ������ ���� �ð� ����   

int BFS(){

	queue<pair<int,int> > q;
	
	q.push({1, 0}); // {ȭ�� ���� , Ŭ������ ����} 
	time[1][0] = 0; // ó���� ȭ��1�� Ŭ������0�� ���� 0��   
	
	int screen=0, clip=0;
	
	while(!q.empty()){
	
		screen = q.front().first;
		clip = q.front().second;
		 
		q.pop();
		
		if(screen == S) { // S�� �ϼ�  
			break;
		}
		
		// ����, ����, �ٿ��ֱ�  
		int nextScreen[4] = {screen, screen-1, screen+clip};
		int nextClip[4] = {screen, clip, clip};
		
		for(int i = 0; i < 3; i++){
			
			if(nextScreen[i] < 0 || nextScreen[i] > S*2 ) continue; // �ε��� 
			if(time[ nextScreen[i] ][ nextClip[i] ] != 0) continue; // �̹� �湮  

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
