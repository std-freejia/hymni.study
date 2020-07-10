#include<stdio.h>
using namespace std;

// 1,2,3 더하기 (백준 9095) std-freejia

 
int combi_Sum(int num){
	
	if(num == 1){
		return 1;
	}else if(num == 2){
		return 2;
	}else if(num == 3){
		return 4;
	}
	
	return combi_Sum(num-1) + combi_Sum(num-2) + combi_Sum(num-3);
}
 
int main(void)
{
	freopen("input.txt", "rt", stdin);
	int i = 0, num = 0, repeat = 0;
	
	scanf("%d", &repeat);
	
    for(i = 0; i <repeat; i++){
    	scanf("%d", &num);
    	printf("%d\n", combi_Sum(num));
	}
    
    return 0;
}

