#include <stdio.h>
#include <vector>
using namespace std;

// 이진검색트리 (백준 5639) std-freejia

/*
이진검색트리의 전위순회 결과가 주어진다. 후위순회 결과를 출력하시오. 
전위 : 루트 -> 왼-> 오 
후위 : 왼-> 오-> 루트  
*/ 

vector<int> node;

void rounds(int start, int end){

	if(start >= end){ // 기저사례 
		return;
	}
	
	if(start == end -1) { // 1개 남았을 때  
		printf("%d\n", node[start]);
		return;
	}
	
	int slice_idx = start+1; // 루트보다 큰 노드 나올 때 까지 인덱스 구하기  
	
	while(node[slice_idx] < node[start] && slice_idx < end){ 
		slice_idx++;
	}
	
	rounds(start+1, slice_idx);
	rounds(slice_idx, end);
	printf("%d\n", node[start]);
	return;
}

int main(void){

	freopen("input.txt", "rt", stdin);
	int i = 0;
	int input = 0;

	
	while(scanf("%d", &input) != EOF){
		node.push_back(input);
	}
	
	rounds(0, node.size());	
	 
	return 0;
}
