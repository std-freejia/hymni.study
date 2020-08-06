#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct Node{
	char data;
	Node* left;
	Node* right;
}Node;

int node_cnt;
Node* node_list;


void preorder(Node* n)
{
    printf("%c", n->data);
    
    if(n->left)
    	preorder(n->left);
     
    if(n->right)
    	preorder(n->right);
}

void inorder(Node* n)
{
    if(n->left)
    	inorder(n->left);
    
    printf("%c", n->data);
    
    if(n->right)
    	inorder(n->right);
}


void postorder(Node* n)
{
    if(n->left)
    	postorder(n->left);
  
    if(n->right)
    	postorder(n->right);
    	
    printf("%c", n->data);
}


int main()
{
    int i = 0, num = 0;
	char root, left, right;
	
	freopen("input.txt" , "rt", stdin);
	
	scanf("%d", &node_cnt);
	
	node_list = (Node*)malloc(sizeof(Node) * node_cnt);
	
    for (i = 0; i < node_cnt; i++)
    {
	//scanf("%c %c %c", &root, &left, &right);
		cin >>root>>left>>right;
		
		node_list[num - 'A'].data = root;
		
		if(left == '.'){ 
			node_list[num - 'A'].left = NULL;
		}else{
			node_list[num - 'A'].left = &node_list[left-'A'];
		}
		
		if(right == '.'){ 
			node_list[num - 'A'].right = NULL;
		}else{
			node_list[num - 'A'].right = &node_list[right-'A'];
		}
		
       
    }

    preorder(&node_list[0]);
    printf("\n");
    inorder(&node_list[0]);
    printf("\n");
    postorder(&node_list[0]);

    return 0;
}
