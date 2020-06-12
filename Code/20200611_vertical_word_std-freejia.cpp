#include <stdio.h>
#include <string.h>

// 세로읽기 (정올) 2020-06-10
// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2119&sca=2050
 

int main(int argc, char** argv){

	int i = 0, j = 0;
	int words_length = 0, max_length = 0;
	char words[5][15] = {0,};
	
	freopen("input.txt", "rt", stdin);
	
	for(i=0; i<5; i++){
		scanf("%s", &words[i]);
		getchar();
		words_length = strlen(words[i]);
		
		if(max_length < words_length){
			max_length = words_length;
		}
	}	
	
	for(i=0; i<max_length; i++){// 세로  
		for(j=0; j<5; j++){
			if('\0' != words[j][i]){
				printf("%c", words[j][i]);
			}
		}
	}	

	return 0;
}

