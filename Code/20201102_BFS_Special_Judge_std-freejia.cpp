#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
#include <set>
using namespace std;

// BFS ����� ���� (BOJ 16940) 

int N; // ���� ���� 
vector<int> B[100001]; // ��������Ʈ 
int visited[100001]; // �湮 üũ 
queue<int> q, input_q;

int BFS(){

	while(!q.empty()){
		int current = q.front(); 
		q.pop();
		
		set<int> s; // �ߺ������ϰ� ���� ��ȣ ������ set  
		
		for(int i : B[current]){ // ���� ����� ���� �������� �ִ��� Ȯ��   
			if(visited[i]) continue; // �̹� �湮�Ѱ� ����
			visited[i] = true; // �湮ǥ��  
			s.insert(i); // �湮 �ؾ��� �͵� set�� ����  
		}
		
		// input_q ���� ���󰡱�. 
		for(int i = 0; i < (int)s.size(); i++){
			if(input_q.empty()) return false; // �湮 �� ���� ���� ����  
			
			int candidate = input_q.front(); // ���� �湮�� ������ ����. 
			input_q.pop();
			
			// �ĺ��� set�� ���ٸ�, ���� �湮�� ������ ������ ���������� �������� �����Ƿ� ����.  
			if(s.find(candidate) == s.end()) return false;
			else q.push(candidate);
		}
	}
	
	return true;		
}

bool solve(){

	int first = input_q.front(); 
	input_q.pop();
	if(first != 1) return false; // ���� ������ 1�̾�� �Ѵ�  
	
	visited[first] = true;
	
	q.push(first); // �湮�����ϱ� ť�� �ִ´� 
		
	bool answer = BFS(); // BFS Ž�� ����  
		
	return answer;
}

void input(){ // ������ �Է¹޴´�  

	cin >> N; // ���� ����  
	int a=0, b=0; 
	
	for(int i = 1; i < N; i++){ // N-1���� ��������Ʈ ����   
		cin >> a >> b;
		B[a].push_back(b);
		B[b].push_back(a);
	}
	
	for(int i = 0; i < N; i++){ // �־��� �湮 ������ ���� ť�� �ִ´�  
		cin >> a;
		input_q.push(a);
	}
}

int main() {	

 	input(); 
 	
 	bool answer = solve();  
 	
 	cout << answer;
 	
	return 0;
} 
