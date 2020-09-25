#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// N��M(9)  BOJ 15663  (����)  
 
int N, M;
vector<int> v;
int answer[10];
int check[10]; 

void permu(int idx){ // ä�� �ڸ��� ��ġidx 

	if(idx == M){ // ���� ���
	
		for(int i = 0; i < M; i++){
			 cout << answer[i] << ' ';
		} 
		cout << '\n';
		
		return;
	}
	
	int before = -1; // ������ �� ���� ����Ѵ�  
	
	for(int i = 0; i < N; i++){
 
 		if(check[i] > 0 && before != v[i]){ // ���� ���� �ٸ� ���� ���� �Ѵ�.  
 			
	 		check[i] -= 1;
			answer[idx] = v[i];  
			before = v[i]; // ���� ���� ���. 
									           
			permu(idx+1); // ���� �ڸ� ���� ä��� 
			
	 		check[i] +=1 ;
		}
 		
	}
} 

int main(void){

	cin >> N >> M;

	int num = 0;

	for(int i = 0; i < N; i++){
		cin >> num;
		
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < N; i++){ // �� ������ ������ check �迭�� ����  
		int idx = find(v.begin(), v.end(), v[i])-v.begin();
		check[idx]++;	 
	}
	
	// find() : v[i]�� '������ ��ġ'�� iterator�� ��ȯ�Ѵ�.  
	
	permu(0);
	
	return 0;	
}
