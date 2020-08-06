#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int com = 0, line = 0; // 컴퓨터 개수, 연결 선 개수  
int parent[100001];
struct point{ 
	int s, d, w; // 시작  
};
vector<point> node;


int find(int u) {
	if(u == parent[u]){ // u가 부모라면 
		return u;
	}
	
	return parent[u] = find(parent[u]); // 재귀호출 하면서 parent 업데이트
} 

bool merge(int u, int v){
	
	u = find(u); 
	v = find(v);
			
	if(u == v) return false; // u와 v가 같은 트리에 속한 경우 종료. 
	
	// u를 v의 자식으로 넣는다. 
	parent[u] = v; 
	
	return true; // 다르니까 합침  
}

bool comp(const point &node_f, const point &node_s) {
	return node_f.w < node_s.w;
}


int main(void){
	
	int i = 0;
	int result = 0;
	 
	freopen("input", "rt", stdin);
	scanf("%d %d", &com, &line);

	for(i=0; i<line; i++){
		int s, d, w = 0;
		scanf("%d %d %d", &s, &d, &w);
		node.push_back({s, d, w});
	} // 입력받기 끝
	
	// 부모는 자기자신 
	for(i=1; i<=com; i++) {
		parent[i] = i;
	}
	
	sort(node.begin(), node.end(), comp); 
	
	for(i=0; i<node.size(); i++){
		if(merge(node[i].s, node[i].d)){ // 다른곳에 속한다면(true) 가중치 추가  
			result += node[i].w;
		}
	}
	
	printf("%d", result);
	return 0;
}
