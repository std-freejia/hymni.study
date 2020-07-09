#include <stdio.h>
#include <algorithm>
using namespace std;

// 일곱난쟁이 (백준 2309) std-freejia

 
int dwarf[10];
int selected[10];
int total_sum;

void Check_select()
{	
	int i = 1, minus = total_sum; 
	
	for(i = 1; i <= 9; i++){
		if(selected[i] == 1){
			minus -= dwarf[i];
		}
	}
	
	if(100 == minus){
		for(i = 1; i <= 9; i++){
			if(selected[i] == 0){
				printf("%d\n", dwarf[i]);
				//minus = total_sum - dwarf[i];
			}
		}
		exit(0); // 프로그램 종료 
	}
		
	return;
}

/* 9개 중에 2개를 고른다 */
void DFS(int idx, int cnt)
{
	int i = 0;
	
	if(cnt == 2){ // 2개를 골라서 total_sum 에서 뻈을때 100인지 확인  
  		
		Check_select();
		return;
	}
	
	for(i = idx; i <= 9; i++){
	
		if(selected[i] == 1) continue;
		
		selected[i] = 1;
		DFS(i, cnt+1);
		selected[i] = 0;
	}

}

int main(void)
{
	freopen("input.txt", "rt", stdin);	
	int i = 0;
	
	for(i = 1; i <= 9; i++){
		scanf("%d", &dwarf[i]);
		total_sum += dwarf[i];
	} // 입력받기 끝. 
	
	sort(dwarf, dwarf+10);
	
	DFS(1, 0);
	
	return 0;
}
