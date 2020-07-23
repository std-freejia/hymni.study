#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

// 트리의 지름 백준 1967  
/*
트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.
노드의 개수 n(1 ≤ n ≤ 10,000)
둘째 줄부터 n번째 줄까지 각 간선에 대한 정보
부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치

루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다. 
*/

vector<pair<int,int>> node[10001];
bool check[10001] = {false, }; // 방문여부  
int diameter_end;
int node_cnt;
int max_sum; // 최대 길이  

void search_max(int start, int sum){
	int i = 0;
	 
	if(!check[start]){
		return;
	}else{
		check[start] = true; // 방문 표시 
	}
		
	if(max_sum < sum){ // 현재가 최대값이라면 합과 시작점을 갱신  
		max_sum = sum;
		diameter_end = start;
	}
	
	for(i = 0; i < node[start].size(); i++){
		search_max(node[start][i].first, sum + node[start][i].second);
	}
} 

int main(void){

	int first, second, len = 0;
	int i = 0;
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &node_cnt);
	
	for(i = 0; i < node_cnt; i++){
		scanf("%d %d %d", &first, second, len);
		node[first].push_back(make_pair(second, len));
		node[second].push_back(make_pair(first, len));
	} // 입력받기 끝  
	
	search_max(1, 0); // 가장 먼 노드
	
	// 초기화  
	max_sum = 0; 
	memset(check, false, sizeof(check));
	
	// 가장 먼 노드 기준으로 가장 먼 노드. 
	search_max(diameter_end, 0);
	
	printf("%d", max_sum);
	
	return 0;
}

