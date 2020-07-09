#include <stdio.h>
#include <vector>
#include <algorithm> // max()
using namespace std;

// 길치 by std-freejia 

vector<vector<int> > map;
int max_sum;
int limit;

void Path(int i, int j, int sum){

	sum += map[i][j];

	if(i == limit && j == limit){ // 도착지점 

		if (max_sum < sum){
			max_sum = sum;
		}
		sum = 0;
		return;
	}
	
	if(i + 1 <= limit) Path(i+1, j, sum);
	
	if(j + 1 <= limit) Path(i, j+1, sum);
} 

int main(void){
	
	freopen("input.txt", "rt", stdin);
	int i, j = 0; 
	scanf("%d", &limit);	
	
	// vector<vector<int> > map(limit+1, vector<int> (limit+1, 0));
	map.assign(limit+1, vector<int> (limit+1, 0));

	for(i=1; i<=limit; i++){
		for(j=1; j<=limit; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(i=1; i<=limit; i++){
		for(j=1; j<=limit; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	Path(1, 1, 0);
	
	printf("%d");
	
	return 0;
}


/* input.txt 

n*n 배열이므로 n과 배열숫자들을 입력받도록 함. 

4
6 7 12 5
5 3 11 18
7 17 3 3 
8 10 14 9

*/
