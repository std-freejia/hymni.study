#include <iostream>
#include <stdio.h>
#include <algorithm> 
#include <vector>
using namespace std;

// �������� ���� (BOJ 11724)  

int N, M; //  ��������, ���� ����  
vector<int> v[500001];
bool check[500001]; // �湮 

void DFS(int start){

	check[start] = true; // �湮ǥ��  
	
	for(int i = 0; i < v[start].size(); i++){
		int next_v = v[start][i];
		 
		if(check[next_v]) continue; // �湮������ ������.
		else DFS(next_v);
	}
}

void solve(){

	int answer = 0;
	for(int i = 1; i <= N; i++){ // ��� ������ �������� Ž��  
		if(!check[i]){
			answer++;
			DFS(i); 
		}
	}
	cout << answer;
 
}

void input(){
 
	cin >> N >> M; // ���� ����, ���� ���� 
	
	int a=0, b=0;
	for(int i = 0 ; i<M; i++){ // ���Ḯ��Ʈ �����  
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	 
}

int main() {	

 	input();
 	solve();

	return 0;
} 
