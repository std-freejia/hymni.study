#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 완전이진트리 

// 1 <= K <= 10 
// 노드 2^k -1 개  
int node[1025];
int depth; // 깊이  

int main(void){

	int start = 1, end = 0; 
	int i = 0, j = 0;
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &depth);
	
	for(i = 0; i < pow(2, depth); i++){
		scanf("%d", &node[i]);
	} // 입력받기 끝 1부터 8까지  
	
	for(i = depth; i >= 1; i--){
	
		for(j = (pow(2, i-1)-1); j < pow(2, depth); j += pow(2, i)){
			printf("%d ", node[j]);
		}		
		printf("\n");
	}
	
	return 0;
}

/* input.txt
3
1 6 4 3 5 2 7
*/

