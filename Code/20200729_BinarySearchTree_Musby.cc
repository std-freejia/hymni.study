#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NUMBER		10000

#define MALLOC(ptr, space)	\
		if(!((ptr) = (int*)malloc(space))){		\
			fprintf(stderr, "Insufficient Memory!");	\
			exit(EXIT_FAILURE);							\
		}

int preorderResult[] = {
	50, 30, 24, 5,
	28, 45, 98, 52,
	60
};

int* BinarySearchTree = NULL;

// [50] [30] [98] [24] [45] [52] [] [5] [28] [] [] [] [60] [] [] [] [] [] -> BinarySearchTree

void CreateBinarySearchTree(int*);
void PrintPostOrder(int, int);

int main(int argc, char* argv[])
{
	int* node = NULL;
	
	MALLOC(node, MAX_NODE_NUMBER);
	memset(node, 0x00, MAX_NODE_NUMBER);
	
	CreateBinarySearchTree(node);
	
	free(node);
	
	return 0;
}

/*
노드 i의 부모 노드  = i/2 (단 i>1)
노드 i의 왼쪽 자식 노드 = i*2 (단 i*2 <=n)
노드 i의 오른쪽 자식 노드  = i*2+1 (단 i*2+1 <= n)
루트 노드 = 1 (단 0<n)
*/

void PrintPostOrder(int depth, int nodeCnt)
{
	int idx = 0;
	
	if(nodeCnt + 1 < idx){
		return;
	}
	
	if(0 != BinarySearchTree[idx]){
		PrintPostOrder(idx << 1, nodeCnt);
		PrintPostOrder((idx + 1) << 1, nodeCnt);
		printf("%d\n", BinarySearchTree[idx]);
	}
}

void CreateBinarySearchTree(int* node)
{
	int idx = 0, idy = 1;
	int nodeCnt = sizeof(preorderResult) / sizeof(int);
	
	while(idx < nodeCnt){
		
		while(1){
			
			if(0 == node[idy]){
				node[idy] = preorderResult[idx];
				break;
			}
			
			(preorderResult[idx] < node[idy]) ? 
			(idy = idy << 1) : idy = (idy << 1) + 1;
				
			continue;
		}
		idx++, idy = 1;		
	}
	
	BinarySearchTree = node;
	
	PrintPostOrder(1, nodeCnt);
	
}