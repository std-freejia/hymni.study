#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
로봇 청소기 백준 14503
by std-freejia
*/

int Search(void); 
int Back_check(void);
 
int cnt_clean, direction, r, c, cnt_check; 
int map[51][51];
 
int main(int argc, char** argv){

	int i, j = 0;
	int height, width = 0;
	int stop_flag = 1;

	// 입력 받기 시작
	scanf("%d %d %d %d %d", &height, &width, &r, &c, &direction);   

	for(i=0; i<height; i++){
		
		for(j=0; j<width; j++){
			scanf("%d", &map[i][j]);
		}
		
	}// 입력 받기 끝  
		
	while(stop_flag){
		stop_flag = Search();
	}
	
	printf("%d", cnt_clean);
	
	return 0;
}

int Back_check(void){ // 후진이 가능하면 1, 불가하면 0 리턴  

	int direc_flag = (direction + 2) % 4;
	
	if(0 == direc_flag){ // 북쪽으로 후진 가능 여부 확인  
	
		if(1 != map[r-1][c]){
			r = r-1;
			return 1;
		}else{
			return 0;
		}
		
	}else if(1 == direc_flag){ // 동쪽으로 후진 가능 여부 확인  
		
		if(1 != map[r][c+1]){
			c = c+1;
			return 1;
		}else{
			return 0;
		}
	}else if(2 == direc_flag){ //  남쪽으로 후진 가능? 
		
		if(1 != map[r+1][c]){
			r = r+1;
			return 1;
		}else{
			return 0;
		}
	}else { // 서쪽으로 후진 가능?  
		
		if(1 != map[r][c-1]){
			c = c-1;
			return 1;
		}else{
			return 0;
		}	
	}
}

int Search(void){

	int temp_d = direction + 3; // 왼쪽 방향을 본다. 
		
	if(map[r][c] == 0){ // 현재 위치를 청소 

		cnt_clean++;
		map[r][c] = 2;
	}
	
	if(0 == temp_d % 4 ) { // 북쪽  
	
		direction+=3; // 회전한다
	
		if(0 == map[r-1][c]) { // 청소 안한 공간이라면  
			r = r-1; // 북쪽으로 전진한다
			cnt_clean++; 
			map[r][c] = 2; // 청소했다는 표시 2   
			cnt_check = 0; 
			
		}else{ // 청소가 되어 있거나 벽이다. 
			cnt_check++; // 북쪽을 확인했음을 센다.  
		}	
		
	}else if(1 == temp_d % 4){ // 동쪽  
	
		direction+=3; // 회전한다
		
		if(0 == map[r][c+1]) { // 청소 안한 공간이라면  
			c = c + 1; // 동쪽으로 전진한다
			cnt_clean++; 
			map[r][c] = 2; 
			cnt_check = 0; 
			
		}else{ 
			cnt_check++;
		}	
		
	}else if(2 == temp_d % 4){ // 남쪽   
		
		direction+=3; // 회전한다	
		
		if(0 == map[r+1][c]) { // 청소 안한 공간이라면  
			r = r+1; // 남쪽으로 전진
			cnt_clean++; 
			map[r][c] = 2; 
			cnt_check = 0; 
		}else{ 
			cnt_check++;
		}	
	}else{ //서쪽  
	
		direction+=3; // 회전한다	
			
		if(0 == map[r][c-1]) { 
			c = c-1; // 서쪽으로 전진한다
			cnt_clean++; 
			map[r][c] = 2; // 청소했다는 표시
			cnt_check = 0; 
			
		}else{ 
			cnt_check++;
		}	
	}

	if(cnt_check == 4){  // 4방향 모두 확인 후, 후진 가능 여부 확인  
		
		if(Back_check()){ // 후진 가능  
			cnt_check = 0;
			return 1; 
			
		}else{ // 후진 불가  
			return 0; // 작동 종료  
		}
		
	}else{ // 다른 방향을 확인해본다  
		return 1;
	}
}

