#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// blackjack  백준 2798 (2020-06-19 freejia)

int cnt_cards, sum_limit, max_sum;
int cards[101];
bool choose[101]; 

int Sum_check(void){
	
	int sum = 0, i = 0;
	
	for(i=0; i<cnt_cards; i++){
		if(choose[i]){
			sum += cards[i];
		}
	}
	
	return sum;
} 

void Combination(int idx, int cnt_choose){ 
	
	int temp_sum = 0;
	
	if (cnt_choose == 3){
		// 합을 세 본다. 
		temp_sum = Sum_check();
		
		if(temp_sum > max_sum && temp_sum <= sum_limit){ // 최대이면서 제한값 안넘는 수. 
			max_sum = temp_sum;
		}
		//printf("%d\n", temp_sum);
		return;
	}
	
	for(int i = idx; i<cnt_cards; i++){
		
		if(choose[i] == true){ // 이미 뽑은 것이면 지나간다  
			continue;
		}
		choose[i] = true; // 하나 뽑음 표시. 
		
		Combination(i+1, cnt_choose+1);
		
		choose[i] = false; // 안뽑는 것으로 되돌리기.  
	}
} 

int main(int argc, char** argv){

	int i = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cnt_cards, &sum_limit); // 입력 받기 시작  

	for(i=0; i<cnt_cards; i++){
		scanf("%d", &cards[i]);
	}// 입력 받기 끝  
	
	Combination(0, 0); 
	
	printf("%d", max_sum);
	
	return 0;
}


