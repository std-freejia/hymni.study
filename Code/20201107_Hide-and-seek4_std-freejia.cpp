#include <iostream> 
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 100000
using namespace std;

// ���ٲ���4  (BOJ 13913) 

int N, K; // ������ġ , ������ġ  

int from[MAX+1];  // ��� �Դ���  
int time[MAX+1]; // �湮���� �� �ð�  

void BFS(){
	
	queue<int> q;
	
	q.push(N);
	time[N] = 0; // ��������  
	
	while(!q.empty()){
	
		int now = q.front(); // ���� ����  
		q.pop();
		
		if(now == K) { // ���� ã�Ҵ� 
			break; 
		} 
		
		if(now - 1 >= 0 && time[now-1] == 0){
			from[now-1] = now;
			q.push(now-1);
			time[now-1] = time[now] + 1; // 1�� �� �귶��.  
		}
		
		if(now + 1 <= MAX && time[now+1] == 0){
			from[now+1] = now;
			q.push(now+1);
			time[now+1] = time[now] + 1; // 1�� �� �귶��.  
		}
		
				
		if(now * 2 <= MAX && time[now*2] == 0){
			from[now*2] = now;
			q.push(now*2);
			time[now*2] = time[now] + 1; // 1�� �� �귶��.  
		}
	
	}
}

void out(){ // ��� ���� ���  

	// ���� �ð� ��� 
	cout << time[K] << '\n'; 

 	stack<int> path;
 	
 	int index = K; //������������ �����ؼ� ��������N ���� �Ž��� �ö󰣴�.  
 	path.push(K);
 	
	while(index != N){ 
		path.push(from[index]);
		index = from[index];
	} 	

	while(!path.empty()){
		cout << path.top() << ' ';
		path.pop();
	}
 	
}
 
void input(){

	cin >> N >> K; // ���� ��ġ, ���� ��ġ 
}

int main() {	

 	input();
	BFS();
	out(); // ��� ���  

	return 0;
} 
