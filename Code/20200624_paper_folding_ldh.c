#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//ldh
//programmers folding_paper

int* solution(int n) {
    // return할 변수는 malloc을 이용해서 초기화해야합니다.
    int* answer;
    int center = 0;
    int idx, idy = 0;
       
    answer = (int*)malloc(sizeof(int) * ((int)pow(2, n) -1));
          
    for(idx = 0; idx < n; idx++)
    {
        center = (int)pow(2, idx) -1;
        answer[center] = 0;
        for(idy = 0; idy < center; idy++)
        {
            answer[(center * 2) - idy] = !answer[idy];
        }
    }
        
    return answer;
}