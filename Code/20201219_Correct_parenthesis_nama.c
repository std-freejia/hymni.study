#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {
    bool answer = true;
    
    if(strlen(s) == 0){
        answer = false;
        return answer;
    }

    int bracketCnt = 0;    
    for(int idx = 0; idx < strlen(s); idx++){
        
        if(s[idx] == '('){
            bracketCnt++;
        }else{
            bracketCnt--;
        }
        
        if(bracketCnt < 0){
            answer = false; 
            break;
        } 
    }
    
    if(bracketCnt != 0){
        answer = false;
    }
    
    return answer;
}