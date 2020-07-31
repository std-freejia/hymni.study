#include <stdio.h>
#include <stdlib.h>

//ldh
//BAEKJOON 5639, Binary Search Tree

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* insertData(Node* tree, int data);
Node* addNode(int data);
int postorder(Node* tree);

int main(int argc, char *argv[], char *env[])
{
	int value = 0;
	Node *tree = NULL;
	
	while(scanf("%d", &value) != EOF)	//preorder로 입력받음
	{
		tree = insertData(tree, value);
	}
	
	postorder(tree);
	
	return 0;
}

Node* insertData(Node* tree, int data)
{
	if(tree == NULL)	//트리가 비어있으면 노드 생성
	{
		tree = addNode(data);
		return tree;
	}
	else if(data < tree->data)	//루트데이터보다 작으면 왼쪽 서브트리
	{
		tree->left = insertData(tree->left, data);
	}
	else if(data > tree->data)	//루트 데이터보다 크면 오른쪽 서브트리
	{
		tree->right = insertData(tree->right, data);
	}
	
	return tree;
}
	
Node* addNode(int data)
{
	Node* tree = (Node*)malloc(sizeof(Node));
	
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	
	return tree;
}

int postorder(Node* tree)
{
	if(tree == NULL)	//트리가 생성안됐을 경우 처리
	{
		return 0;
	}
	
	postorder(tree->left);
	postorder(tree->right);
	
	printf("%d\n", tree->data);
	
	return 0;
}
