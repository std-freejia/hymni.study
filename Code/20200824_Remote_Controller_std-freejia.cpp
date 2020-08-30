#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX_CH 1000000
using namespace std;

// 리모컨 (BOJ 1107)  

int N, M; 
bool broken[11]; //0~9 버튼   true면 고장  
int min_cnt = 2147000000;
 
int check_broken(int ch){ 

	int cnt = 0; // 버튼을 눌러야할 횟수  
	
	if(ch == 0){
		if(broken[0]) return 0; // 못 누름  
		else return 1;
	}
	
	while(ch > 0){
		if(broken[ch % 10]) return 0; // 못 누름 		
		ch /= 10;
		cnt++;
	}
	
	return cnt;
}

int main(void){

	freopen("input.txt", "rt", stdin);
 	
 	cin >> N >> M; // 목표 채널, 고장 버튼개수  
	
	int ch = 0;
	
	for(int i = 0; i < M; i++){
		cin >> ch;
		broken[ch] = true; // 고장을 true로 표시  
	} 
	
	// 목표 채널로 '숫자만' 눌러서 이동하는 횟수 
	int answer = abs(N-100); // 현재 채널100과의 차이  
	
	// 목표 채널로 숫자와 +/- 함께 눌러서 이동하는 횟수  
	for(int i = 0; i <= MAX_CH; i++){
	
		ch = i;
		
		// 고장버튼 확인 후, 눌러야할 버튼 횟수  
		int cnt_bt = check_broken(ch);	 
		// 숫자만 눌러서 이동  
		int num_press = abs(N-ch);
		
		if(cnt_bt > 0){
			answer = min(answer, num_press + cnt_bt);
		}
	} 
	
 	cout << answer;
	
	return 0;
	
}
