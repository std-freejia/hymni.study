#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<int> v; 
int answer;

int gcd(int a, int b){
	
	if(b == 0) return a;
	else return gcd(b, a%b); 
}

void solve(){

	// ���밪���� �ִ����� 
	answer = v[0];
	for(int i = 1; i < v.size(); i++){
		answer = gcd(answer, v[i]);
	} 
	cout << answer;
} 

void input(){
    
	cin >> N >> S; //  ���� �� ������. ���� ��ġ. 
	
	int n = 0;
	
	for(int i = 0; i < N; i++){
		scanf("%d", &n);
		v.push_back(abs(n-S)); // ���� ��ġ�� ���� ��ġ ���� ���� ���밪  
	} 
	//sort(v.begin(), v.end()); // ����  
}


int main() {	
 
 	input();
	solve(); 
	
	return 0;
} 
