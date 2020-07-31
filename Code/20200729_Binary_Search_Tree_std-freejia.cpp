#include <stdio.h>
#include <vector>
using namespace std;

// �����˻�Ʈ�� (���� 5639) std-freejia

/*
�����˻�Ʈ���� ������ȸ ����� �־�����. ������ȸ ����� ����Ͻÿ�. 
���� : ��Ʈ -> ��-> �� 
���� : ��-> ��-> ��Ʈ  
*/ 

vector<int> node;

void rounds(int start, int end){

	if(start >= end){ // ������� 
		return;
	}
	
	if(start == end -1) { // 1�� ������ ��  
		printf("%d\n", node[start]);
		return;
	}
	
	int slice_idx = start+1; // ��Ʈ���� ū ��� ���� �� ���� �ε��� ���ϱ�  
	
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
