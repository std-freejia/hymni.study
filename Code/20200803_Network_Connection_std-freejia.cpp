#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int com = 0, line = 0; // ��ǻ�� ����, ���� �� ����  
int parent[100001];
struct point{ 
	int s, d, w; // ����  
};
vector<point> node;


int find(int u) {
	if(u == parent[u]){ // u�� �θ��� 
		return u;
	}
	
	return parent[u] = find(parent[u]); // ���ȣ�� �ϸ鼭 parent ������Ʈ
} 

bool merge(int u, int v){
	
	u = find(u); 
	v = find(v);
			
	if(u == v) return false; // u�� v�� ���� Ʈ���� ���� ��� ����. 
	
	// u�� v�� �ڽ����� �ִ´�. 
	parent[u] = v; 
	
	return true; // �ٸ��ϱ� ��ħ  
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
	} // �Է¹ޱ� ��
	
	// �θ�� �ڱ��ڽ� 
	for(i=1; i<=com; i++) {
		parent[i] = i;
	}
	
	sort(node.begin(), node.end(), comp); 
	
	for(i=0; i<node.size(); i++){
		if(merge(node[i].s, node[i].d)){ // �ٸ����� ���Ѵٸ�(true) ����ġ �߰�  
			result += node[i].w;
		}
	}
	
	printf("%d", result);
	return 0;
}
