#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 스킬 순서 중 순서(Index)를 찾는 함수
int findIndex(char *skill,char s){
    for(int idx = 0; idx < strlen(skill); idx++){
        if(skill[idx] == s){
            return idx;
        }
    }
    
    return -1;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0, idxWhere, flag, tmpIdx;
    
    for(int treeIdx = 0; treeIdx < skill_trees_len; treeIdx++){
        tmpIdx = flag = 0;
        for(int skillIdx = 0; skillIdx < strlen(skill_trees[treeIdx]); skillIdx++){
            // 찾은 Index 값
            idxWhere = findIndex(skill, skill_trees[treeIdx][skillIdx]);
            
            // 스킬 순서에 관련 없는 스킬 
            if(idxWhere == -1){
                continue;
            
            // 순서에 어긋나는 스킬
            }else if(idxWhere != tmpIdx){
                flag = 1;
                break;
            
            // 순서에 맞는 스킬
            }else if(idxWhere == tmpIdx){
                tmpIdx++;
            }
        }
        if(flag == 0){
            answer++;
        }   
    }
    
    return answer;
}