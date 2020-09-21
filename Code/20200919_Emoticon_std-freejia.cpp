#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;

// �̸�Ƽ�� BOJ 14226 (����) 

int S; 
bool check[MAX+1][MAX+1];  // ȭ���� �̸�Ƽ�� ����, Ŭ������ �̸�Ƽ�� ����  

int BFS(){

	// ȭ���� �̸�Ƽ�� ����, Ŭ�������� �̸�Ƽ�� ����, �ð�  
	int imo=0, clip=0, time=0;
	
	queue<pair<pair<int,int>, int> > q;
	
	//�̸�Ƽ�� 1���� ����  
	q.push({{1, 0}, 0});
	check[1][0] = true;
		
	while(!q.empty()){
	
		imo = q.front().first.first;
		clip = q.front().first.second;
		time = q.front().second;
		
		q.pop();
		
		if(imo == S){ // S�� �ϼ�  			
			break; 
		}
		
		// ����  
		if(imo > 0 && imo < MAX){ // imo�� 0���� Ŀ�� ���� ����  
			if(!check[imo][imo]){
				check[imo][imo] = true;
				q.push({{imo, imo}, time+1});
			}
		}
		
		// �ٿ��ֱ�  
		if(clip > 0 && imo+clip <= MAX){ // clip�� 0���� Ŀ�� �ٿ��ֱ� ����. �ε��� üũ  
			if(!check[imo+clip][clip]){
				check[imo+clip][clip] = true;
				q.push({{imo+clip, clip}, time+1});
			}  
		}
		
		//����
		if(imo-1 >= 0 && !check[imo-1][clip] ){ 
			q.push({{imo-1, clip}, time+1});
		}	 
	} 
	
 	return time; 
}

int main(void){
 
 	cin >> S;
 
	printf("%d", BFS());  // �ּҽð� ����  	 
 
	return 0;
} 
