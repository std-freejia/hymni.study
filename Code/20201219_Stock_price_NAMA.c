#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(4 * prices_len);
    
    // 주식 가격 array search
    for(int idx = 0; idx < prices_len; idx++){
        int downSec = 0;
        
        // 해당 가격 시점으로부터 뒤로 비교
        for(int subIdx = idx + 1; subIdx < prices_len; subIdx++){
            downSec++;
            if(*(prices+idx) > *(prices+subIdx)){
                break;
            }
        }
        *(answer + idx) = downSec;
    }
    
    return answer;
}