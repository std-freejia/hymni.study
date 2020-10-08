#include <iostream>
#include <queue>
#include <algorithm> 
#define MAX 100000
#define INF 987654321
using namespace std;

// ���ٲ���3   ����  
 
int N, K;
queue<int> q;
int visit[MAX + 1];  	// i��ġ���� �ּ��� �ð��� �����ϴ� visit�迭

int BFS(){

	q.push(N);
	visit[N] = 0; // N�������� ������ �� �ð��� 0��. 
	
	while(!q.empty()){
	
		int X = q.front(); // ���� ����  
		q.pop();
		
		if(X == K) { // �������� ���� 
			return visit[X]; // X������ ������ �ð��� ����  
		}
		
		for(int nextX : {X*2, X-1, X+1}){
		
			if(nextX < 0 || nextX > MAX) continue; // �ε��� �ʰ��� �Ȱ���. 
			
			if(visit[nextX] > visit[X]+1){ // ������ 
				if(2*X == nextX) visit[nextX] = visit[X];
				else visit[nextX] = visit[X]+1; 
				q.push(nextX); 
			}
		}
		
	}
}

int main(void){
 
 	//freopen("input.txt", "rt", stdin);
 	
 	scanf("%d %d", &N, &K);
 	
 	for(int i = 0; i <= MAX; i++){ // ū ���� �ʱ�ȭ �صд� 
 		visit[i] = INF; 
	}

	int answer = BFS(); 
	
	cout << answer;
 
	return 0;
} 


