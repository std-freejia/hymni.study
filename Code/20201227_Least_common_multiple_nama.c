#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 0;
    
    int maxNum = 0;
    // N개의 수 중 가장 큰 수 찾기
    for(int idx = 0; idx < arr_len; idx++){
        if(arr[idx] > maxNum){
            maxNum = arr[idx];
        }
    }
    
    // maxNum을 하나씩 증가시키며 N개의 수로 나누어 떨어지는지 확인
    while(1){
        int lcmCnt = 0;
        for(int idx = 0; idx < arr_len; idx++){
            if((maxNum % arr[idx]) != 0) break;
            lcmCnt++;
        }
        
        if(lcmCnt == arr_len){
            answer = maxNum;
            break;
        }
        
        maxNum++;
    }    
        
        
    return answer;
}