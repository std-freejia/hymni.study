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

	// 절대값들의 최대공약수 
	answer = v[0];
	for(int i = 1; i < v.size(); i++){
		answer = gcd(answer, v[i]);
	} 
	cout << answer;
} 

void input(){
    
	cin >> N >> S; //  동생 몇 명인지. 수빈 위치. 
	
	int n = 0;
	
	for(int i = 0; i < N; i++){
		scanf("%d", &n);
		v.push_back(abs(n-S)); // 수빈 위치와 동생 위치 간의 차이 절대값  
	} 
	//sort(v.begin(), v.end()); // 정렬  
}


int main() {	
 
 	input();
	solve(); 
	
	return 0;
} 
