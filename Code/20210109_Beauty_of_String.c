#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
long long solution(const char* s) {
    long long answer = 0;

    char tmpCh;
    
    // 전체 문자열 길이
    int sLength = strlen(s);
    int sameFlag = 1;
    
    // 모두가 같은 문자일 때
    for(int sIdx = 1; sIdx < sLength; sIdx++){
        if(s[0] != s[sIdx]){
            break;
        }else if(sIdx == sLength-1){
            sameFlag = -1;
        }
    }
    
    if(sameFlag == -1){
        return 0;
    }
    
    
    // 문자가 같은 경우 Index에서 갈 수 있는 가장 가까운 방법 저장
    int *rDiff = (int*)malloc(sizeof(int) * sLength);
    int *lDiff = (int*)malloc(sizeof(int) * sLength);
    for(int sIdx = 0; sIdx < sLength; sIdx++){
        tmpCh = s[sIdx];
        
        // rDiff
        for(int cmpIdx = sIdx; cmpIdx < sLength; cmpIdx++ ){
            if(tmpCh != s[cmpIdx]){
                rDiff[sIdx] = cmpIdx;
                break;
            }else if(cmpIdx == sLength-1){
                rDiff[sIdx] = sLength;
                break;
            }
        }
        
        // lDiff
        for(int cmpIdx = sIdx; cmpIdx >= 0; cmpIdx--){
            if(tmpCh != s[cmpIdx]){
                lDiff[sIdx] = cmpIdx;
                break;
            }else if(cmpIdx == 0){
                lDiff[sIdx] = -1;
                break;
            }
        }
        // printf("[%d] r: %d l: %d\n", sIdx, rDiff[sIdx], lDiff[sIdx]);            
    }

    // printf("---------------------\n");
    int resTmp;
    for(int idxL = 0; idxL < sLength; idxL++){
        for(int idxR = sLength-1; idxR >= idxL; idxR--){
            // 두 인덱스가 같은 경우
            if(idxL == idxR){
                continue;
            }else{
                if(s[idxL] == s[idxR]){
                    // idxL 혹은 idxR을 움직였을 때 최적의 결과를 찾음
                    resTmp = (idxR - rDiff[idxL]) > (lDiff[idxR] - idxL) ? (idxR - rDiff[idxL]):(lDiff[idxR] - idxL);
                    if(resTmp >= 0){
                        answer += resTmp;
                    }else{
                        break;
                    }
                }else{
                    answer += idxR - idxL;
                }
                    
                // printf("[%d:%d] %d %d | %d %d \n", idxL, idxR, rDiff[idxL], lDiff[idxR], idxR - rDiff[idxL], lDiff[idxR] - idxL);
            }
        }   
    }    
    
    free(rDiff);
    free(lDiff);
    
    return answer;
}