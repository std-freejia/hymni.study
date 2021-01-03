#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(s[0])* strlen(s));
    strcpy(answer,s);
    
    int charIdx = 0;
    for(int strIdx = 0; strIdx < strlen(answer); strIdx++){
        if(answer[strIdx] == ' '){
            // 공백문자 출현시 Index 초기화
            charIdx = 0;
        }else if(isalpha(answer[strIdx])){        
            if(charIdx % 2 == 0){
                // Index 짝수 & 소문자
                if(answer[strIdx] >= 97 && answer[strIdx] <= 122){
                    answer[strIdx] -= 32;
                }
            }else{
                // Index 홀수 & 대문자
                if(s[strIdx] >= 65 && s[strIdx] <= 90){
                    answer[strIdx] += 32;
                }
            }
            charIdx++;
        }
    }
    
    return answer;
}